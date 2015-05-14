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
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vii city[10001];
int wei[10001];
int C,R,D;
const int MAX = (1<<31)-1;

int minw = MAX;
int c;

priority_queue<ii,vii,less<ii> > q;

int main()
{
	cin >> C >>R >>D;
	for(int i=0;i!=R;i++)
	{
		int a,b,c;
		cin >> a >> b >>c;
		city[a].push_back(make_pair(b,c));
		city[b].push_back(make_pair(a,c));
	}
	for(int i=0;i!=C;i++)wei[i]=-1;
	wei[1] = MAX;
	q.push(ii(MAX,1));
	while(!q.empty())
	{
		ii top = q.top(); q.pop();
		int v = top.second,w=top.first;
		if(wei[v] <= w)
		{
			for(vii::iterator it = city[v].begin();it!=city[v].end();it++)
			{
				int v2 = it->first,w2 = it->second;
				if(wei[v2]==-1)
				{
					wei[v2] = w2;
					q.push(ii(wei[v2],v2));
				}
				else if(wei[v2] < min(wei[v],w2)) 
				{
					wei[v2] = min(wei[v],w2);
					q.push(ii(wei[v2],v2));
				}
			}
		}
	}
	for(int i=0;i<D;i++)
	{
		cin >> c;
		if(wei[c]<minw) minw = wei[c];
	}
	cout << minw << endl;
	return 0;
}

/* Andrew <3 
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
#include <climits>

using namespace std;

int cities,road,dest;
int graph[10001];
int dests[10001];
vector<pair<int,int> > roads[10001];

int main()
{
	cin >> cities >> road >> dest;
	for(int i=0;i!=cities;i++)
		graph[i] = -1;
	for(int i=0;i!=road;i++)
	{
		int citya,cityb,maxwei;
		cin >> citya >> cityb >> maxwei;
		roads[citya].push_back(make_pair(cityb,maxwei));
		roads[cityb].push_back(make_pair(citya,maxwei));
	}
	for(int i=1;i<=cities;i++)
	for(int j=0;j!=roads[i].size();j++)
	{
		int end = roads[i][j].first-1;
		graph[end] = max(graph[end],roads[i][j].second);
	}
	int small = INT_MAX;
	for(int i=0;i!=dest;i++)
	{
		int d;
		cin >> d;
		small = min(small,graph[d-1]);
	}
	cout << small << endl;
	return 0;
}
*/