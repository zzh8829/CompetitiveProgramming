#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define rep(k, a, b) for (int k = (a); k < int(b); k++)
#define rrep(k, a, b) for (int k = (a); k >= int(b); k--)
#define irep(it, xs) for (auto it = xs.begin(); it!=xs.end(); it++)
#define rirep(it, xs) for (auto it = xs.rbegin(); it!=xs.rend(); it++)
#define erep(e, xs) for (auto& e : (xs))
#define rint(x) scanf("%d", &(x))
#define rfloat(x) scanf("%lf", &(x))

typedef long long LL;
typedef pair<int,int> II;

int N,R,C;

int gd[101][101];

int dr[]={0,0,1,-1};
int dc[]={1,-1,0,0};

int main()
{
	int T;
	rint(T);
	rep(t, 0, T)
	{
		rint(R);rint(C);rint(N);
		int ans = INT_MAX;
		//cout << "WTF" << endl;
		for(int i=0;i!=(1<<(R*C));i++)
		{
			//cout << i << endl;
			bitset<16> bs(i);
			if(bs.count()==N)
			{
				memset(gd,0,sizeof(gd));
				for(int r=0;r<R;r++)
				for(int c=0;c<C;c++)
				{
					gd[r+1][c+1]=bs[r*C+c];
				}
				int tot = 0;
				for(int r=1;r<=R;r++)
				for(int c=1;c<=C;c++) if(gd[r][c])
				{
					for(int d=0;d!=4;d++)
					{
						if(gd[r+dr[d]][c+dc[d]])
						{
							tot++;
						}
					}
				}
				/*
				for(int r=0;r<=R+1;r++)
				{
					for(int c=0;c<=C+1;c++)
					{
						cout << gd[r][c] << " ";
					}
					cout << endl;

				}
				cout << tot << endl;
				*/
				ans = min(ans, tot/2);
			}
		}
		printf("Case #%d: %d\n",t+1, ans);
	}

	return 0;
}