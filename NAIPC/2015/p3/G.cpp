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
#include <iomanip>
using namespace std;

double dp[151];
int s[151];
double p[151];

int main()
{
	int cc;
	cin >> cc;
	for(int c=0;c!=cc;c++)
	{
		int n;
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			cin >> s[i] >> p[i];
			p[i]/=100.0;
		}
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(int i=0;i!=n;i++)
			for(int x=150;x>=s[i];x--)
				dp[x] = max(dp[x],p[i] * dp[x-s[i]]);
		double maxn = 0;
		for(int i=76;i<=150;i++)
			maxn = max(maxn, dp[i]);
		cout << fixed << setprecision(8) << maxn*100 << endl;
	}
	return 0;
}