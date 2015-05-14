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

int N;

typedef pair<int,int> I2;

I2 pts[2001];
int best[2001];
int pbest[2001];
double pdist[2001];

struct line
{
	int a, b;
	double d;

	bool operator < (const line& l) const
	{
		return d < l.d;
	}
};

int main()
{
	scanf("%d",&N);
	N++;

	for(int i = 0;i!=N-1;i++)
		scanf("%d%d",&pts[i+1].first, &pts[i+1].second);

	for(int i = 0;i!=N;i++)
		pdist[i] = -1;

	vector<line> V;
	for(int i = 0;i!=N;i++)
	{
		for (int j = i+1; j < N; j++)
		{
			line l;
			l.a = i;
			l.b = j;
			int dx = pts[j].first - pts[i].first;
			int dy = pts[j].second - pts[i].second;
			l.d = sqrt(dx * dx + dy * dy);
			V.push_back(l);
		}
	}

	sort(V.begin(), V.end());

	for(int i = 0;i!=V.size();i++)
	{
		int a = V[i].a;
		int b = V[i].b;

		if (V[i].d != pdist[a])
		{
			pbest[a] = best[a];
			pdist[a] = V[i].d;
		}
		if (V[i].d != pdist[b])
		{
			pbest[best] = best[b];
			pdist[b] = V[i].d;
		}

		if (a!=0)
		{
            best[a] = max(best[a], 1 + pbest[b]);
            best[b] = max(best[b], 1 + pbest[a]);
		}
		else
		{
            best[a] = max(best[a], pbest[b]);
		}
	}

	printf("%d\n", best[0] + 1);
}
