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
#include <climits>
#include <stack>
using namespace std;

+-+-+-+-+
|x|x|x|x|
+-+-+-+-+
|x|x|x|x|
+-+-+-+-+
|x|x|x|x|
+-+-+-+-+
|x|x|x|x|
+-+-+-+-+

x.x.x.x
.......
x.x.x.x
.......
x.x.x.x
.......
x.x.x.x



int dp[200001];
int best = INT_MIN;
int R,C,n;
vector<int> tr[100001];

typedef pair<int,int> I2;

int main()
{
	cin >> R >> C >> n;
	for(int i=0;i!=n;i++)
	{
		int a,b;
		cin >> a >> b;
		tr[a].push_back(b);
	}
	for(int i=0;i<=R;i++)
	{
		for(int j=0;j<=C;j++)
			dp[j]++;
		for(int j=0;j!=tr[i].size();j++)
			dp[tr[i][j]]=0;
		
		for(int j=0;j<=C;j++)
			cout << dp[j] << " ";
		cout << endl;
		
		stack<I2> st;
		st.push(I2(0,0));
		for(int j=0;j<=C;j++)
		{
			if(dp[j]<st.top().first)
			{
				int p = 0;
				while(dp[j]<st.top().first)
				{
					p = st.top().second;
					I2 c = st.top();
					int h = c.first;
					int w = j-c.second;
					if(j%1)
					best = max(best,(c.first)*(j-c.second));
					st.pop();
				}
				st.push(I2(dp[j],p));
			} else {
				st.push(I2(dp[j],j));
			}
		}
		int p = st.top().second;
		while(st.size()>1)
		{
			I2 c = st.top();
			best = max(best,(c.first)*(p-c.second+1));
			st.pop();	
		}
	}
	cout << best << endl;
	return 0;
}