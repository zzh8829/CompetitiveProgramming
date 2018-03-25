#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main()
{
	int ls,n,maxh;
	cin >>ls;
	for(int l=0;l!=ls;l++)
	{
		maxh = 0;
		vector<string> vs;
		string str;
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			cin >> str;
			vs.push_back(str);
		}
		vector<string> tree(1,vs[n-1]);
		for(int i=0;i!=n-1;i++)
		{
			if(tree.size()<2||tree[tree.size()-2]!=vs[i]) 
				tree.push_back(vs[i]);
			else tree.pop_back();
			if(tree.size()-1>maxh)maxh = tree.size()-1;
		}
		cout << (n-2*maxh)*10<< endl;
	}
	return 0;
}