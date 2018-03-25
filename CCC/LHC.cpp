#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <iterator>
#include <stdint.h>
#include <algorithm>
#include <tr1/array>
#include <functional>
#include <tr1/random>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
using namespace std;

typedef pair<int,int> I2;
typedef long long LL;
int n,maxn;
LL cnt;

struct Node
{
	Node(int t=0,int l=0):to(t),len(l){};
	int to;
	int len;
};

struct Info
{
	Info(int l=0,LL c=0):len(l),cnt(c){};
	int len;
	LL cnt;
};

vector<Node> m[400001];
map<I2,Info> mpp;

void print()
{
	for(int i=0;i!=n;i++)
	{
		cout << "Node: " << i << endl;
		for(int j=0;j!=m[i].size();j++)
		{
			cout << "To: " << m[i][j].to <<  " L: " << m[i][j].len << endl;
		}
	}
	cout << endl;
}

int cur;
int curn;

void dfs(int node,int from,int len)
{
	if(m[node].size()==1)
	{
		if(len > maxn)
		{
			maxn = len;
			cnt = 1;
		} else if(len==maxn) {
			cnt++;
		}
	}
	for(int i=0;i!=m[node].size();i++)
	{
		if(m[node][i].to!=from && len+1 >= m[node][i].len )
		{
			m[node][i].len = len+1;
			int last = cur;
			int lastn = curn;
			dfs(m[node][i].to,node,len+1);
			mpp[I2(m[node][i].to,node)] = cur;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for(int i=0;i!=n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		m[a-1].push_back(Node(b-1,0));
		m[b-1].push_back(Node(a-1,0));
	}
	for(int i=0;i!=n;i++) 
		if(m[i].size()==1)
			dfs(i,-1,1);
	print();
	printf("%d %d\n",maxn,cnt);
	return 0;
}