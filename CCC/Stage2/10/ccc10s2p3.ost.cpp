#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

template<typename T,typename Compare = std::less<T> >
class OST
{
private:
	struct OSTNode
	{
		T key;
		int priority;
		OSTNode* left;
		OSTNode* right;
		int count;
		OSTNode(T k):
			key(k),
			priority(rand()),
			left(0),
			right(0),
			count(0)
		{
		}
		void output(ostream& out, string tab=" ", string type = "root")
		{
			if(right) right->output(out,tab+"  |","right");
			out << tab.substr(0,tab.size()-1) << "+-"  << key <<" C:" << count << endl;
			if(left) left->output(out,tab+"  |","left");
		}
		friend ostream& operator<< (ostream& out, OSTNode& node)
		{
			node.output(out);
			return out;
		}
	};
public:
	OST():
		root(0)
	{
	}
	void insert(T key)
	{
		root = insert(key,root);
	}
	void erase(T key)
	{
		root = erase(key,root);
	}
	T nth_element(int n)
	{
		return nth_element(n,root);
	}
	int size()
	{
		return root?root->count:0;
	}
	friend ostream& operator<< (ostream& out, OST& ost)
	{
		if(ost.root) out << *ost.root;
	}
private:
	T nth_element(int n,OSTNode* parent)
	{
		int nleft = parent->left?parent->left->count:0;
		if(nleft == n)
		{
			return parent->key;
		}
		if(nleft < n)
		{
			return nth_element(n-nleft-1 ,parent->right);
		}
		else
		{
			return nth_element(n,parent->left);
		}
	}
	OSTNode* insert(T key,OSTNode* parent)
	{
		if(!parent)
		{
			parent = new OSTNode(key);
			parent->count = 1;
		} 
		else if( key == parent->key)
		{
			//cout << "[Warning]: duplicate element " << key << endl;
		}
		else if( compare(key, parent->key) )
		{
			parent->count ++;
			parent->left = insert(key, parent->left);
			if(parent->left->priority < parent->priority)
				parent = rotate_right(parent);
		}
		else
		{
			parent->count ++;
			parent->right = insert(key, parent->right);
			if(parent->right->priority < parent->priority)
				parent= rotate_left(parent);
		}
		return parent;
	}
	OSTNode* erase(T key,OSTNode* parent)
	{
		if(parent)
		{
			if( key == parent->key )
			{
				if(parent->left && parent->right)
				{
					if(parent->left->priority < parent->right->priority)
						parent = rotate_right(parent);
					else
						parent = rotate_left(parent);
					parent = erase(key,parent);
				}
				else if(parent->left)
					parent = parent->left;
				else if(parent->right)
					parent = parent->right;
				else
					parent = 0;
			} 
			else if(compare(key,parent->key)) 
			{
				parent->count --;
				parent->left = erase(key, parent->left);
			} 
			else
			{
				parent->count --;
				parent->right = erase(key, parent->right);
			}
		}
		return parent;
	}
	static OSTNode* rotate_left(OSTNode* node)
	{
		OSTNode* right = node->right;
		node->right = right->left;
		right->left = node;

		right->count = node->count;
		node->count = 1;
		if(node->left)node->count += node->left->count;
		if(node->right)node->count += node->right->count;

		return right;
	}
	static OSTNode* rotate_right(OSTNode* node)
	{
		OSTNode* left = node->left;
		node->left = left->right;
		left->right = node;

		left->count = node->count;
		node->count = 1;
		if(node->left)node->count += node->left->count;
		if(node->right)node->count += node->right->count;

		return left;
	}
	Compare compare;
	OSTNode* root;
};

int itor[1000001];

typedef pair<int,int> pii;
OST< pii > ost;

ostream& operator << (ostream& out, pii& ii)
{
	out << ii.first << " " << ii.second;
	return out;
}

int main()
{
	srand(time(0));
	int cs;
	scanf("%d",&cs);
	char cmd;
	int a,b;
	while(cs--)
	{
		cmd = getchar();
		while(cmd==' '||cmd=='\n')cmd = getchar();
		switch(cmd)
		{
		case 'N':
			scanf("%d%d",&a,&b);
			itor[a] = b;
			ost.insert(pii(b,a));
			break;
		case 'M':
			scanf("%d%d",&a,&b);
			ost.erase(pii(itor[a],a));
			ost.insert(pii(b,a));
			itor[a] = b;
			break;
		case 'Q':
			scanf("%d",&a);
			printf("%d\n",ost.nth_element(ost.size()-a).second);
			break;
		}
	}
	return 0;
}