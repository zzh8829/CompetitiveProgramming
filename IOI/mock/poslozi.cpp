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

typedef pair<int,int> I2;

I2 swaps[200];
int N,M;

#define THE_ULTIMATE_ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING 42
#define YOLO_SWAG 420

struct i12
{
	int n[12];
	bool operator<(const i12& o)const {
		for(int i=0;i!=N;i++)
			if(n[i]!=o.n[i])
				return n[i] < o.n[i];
		return n[N-1] < o.n[N-1];
	}
	int& operator[](int idx) {
		return n[idx];
	}
};

i12 seq;

vector<int> vs[12];

int run(vector<int> vi)
{
	i12 seqq = seq;
	int det[12] = {0};
	int tot = 0;
	for(int vii=0;vii!=vi.size();vii++)
	{
		int i = vi[vii];
		if(seqq[i]!=i+1)
		{
			/*
			for(int j=0;j!=N;j++)
				cout << seq[j] << " ";
			cout << endl;
			*/
			queue<pair<i12,I2> > q;
			set<i12> si;
			int a = 0;
			while(seqq[a]!=i+1)a++;
			q.push(make_pair(seqq,I2(0,a)));
			si.insert(seqq);
			bool done = false;
			while(!done && !q.empty())
			{
				i12 c = q.front().first;
				int s = q.front().second.first;
				int a = q.front().second.second;
				q.pop();
				for(int j=0;j!=vs[a].size();j++)if(!det[vs[a][j]])
				{
					i12 nc = c;
					swap(nc[a],nc[vs[a][j]]);
					if(vs[a][j]==i)
					{
						seqq = nc;
						tot += s+1;
						done = true;
						break;
					} else {
						if(!si.count(nc))
						{
							q.push(make_pair(nc,I2(s+1,vs[a][j])));
							si.insert(nc);
						}
					}
				}
			}
			if(q.empty() && !done) return 999999;
		}
		det[i]=true;
	}
	return tot;
}

int main()
{
	//freopen("in.txt","r",stdin);
	srand(time(NULL));
	cin >> N >> M;
	for(int i=0;i!=N;i++)
		cin >> seq[i];
	for(int i=0;i!=M;i++)
	{
		cin >> swaps[i].first >> swaps[i].second;
		swaps[i].first -- ;
		swaps[i].second -- ;
		vs[swaps[i].first].push_back(swaps[i].second);
		vs[swaps[i].second].push_back(swaps[i].first);
	}
	vector<int> vi;
	for(int i=0;i!=N;i++)
		vi.push_back(i);
	int minn = run(vi);
	for(int i=0;i!=THE_ULTIMATE_ANSWER_TO_LIFE_THE_UNIVERSE_AND_EVERYTHING;i++)
	{
		random_shuffle(vi.begin(),vi.end());
		minn = min(minn,run(vi));
	}
	cout << minn << endl;
	return 0;
}