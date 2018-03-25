#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N,C,M;
int cs[300001];
vector<int> cis[10001];

int cunt(int a,int b,int c)
{
	return upper_bound(cis[c].begin(),cis[c].end(),b)-lower_bound(cis[c].begin(),cis[c].end(),a);
}

int tree[2000000];

void update(int node,int a,int b)
{
	if(a > b) return;
	if(a == b) {
		tree[node] = cs[a];
		return;
	}

	update(node*2, a, (a+b)/2);
	update(node*2+1, (a+b)/2+1, b);

	if(tree[node*2] == tree[node*2+1]) {
		tree[node] = tree[node*2];
	} else {
		int c1 = cunt(a,b,tree[node*2]);
		int c2 = cunt(a,b,tree[node*2+1]);
		if(c1 > c2 && c1 > (b-a+1)/2)
			tree[node] = tree[node*2];
		else if( c2 > c1 && c2 > (b-a+1)/2) 
			tree[node] = tree[node*2+1];
		else
			tree[node] = 0;
	}
}

int query(int node, int a,int b,int i,int j)
{
	if( a > b || j < a || i > b) return 0;
	//printf("%d %d %d %d %d: %d\n",node, a,b,i,j,tree[node]);
	if( a>=i && b<=j ) return tree[node];
	int c1 = query(node*2, a,(a+b)/2,i,j);
	int c2 = query(node*2+1, (a+b)/2+1,b,i,j); 
	if(c1 == c2) {
		return c1;
	} else {
		//i - j
		int n1 = cunt(i,j,c1);
		int n2 = cunt(i,j,c2);
		if(n1 > n2 && n1 > (j-i+1)/2)
			return c1;
		else if( n2 > n1 && n2 > (j-i+1)/2) 
			return c2;
		else
			return 0;
	}
}

int main()
{
	scanf("%d%d",&N,&C);
	for(int i=1;i<=N;i++)
	{
		scanf("%d",cs+i);
		cis[cs[i]].push_back(i); 
	}
	update(1,1,N);
	scanf("%d",&M);
	for(int i=0;i!=M;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int c = query(1,1,N,a,b);
		if(!c) {
			cout << "no" << endl;
		} else {
			cout << "yes " << c << endl;
		}
	}
	return 0;
}