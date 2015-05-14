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
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1000000007;
/*

0 1   0 1
1 1   0 2
1 2   1 2
2 2   2 2
3 2   3 2
SL x y = SE y y-1  +

SL 4 3
0 0
===
0 1
===
1 1 |1 2|, |2 2,1 3|
---
0 2 |1 2,0 3|
===

*/

long long se[2001][2001];
long long sl[2001][2001];

int main()
{
	for(int i=1;i!=2001;i++)
	{
		se[i][0] = 1;
		for(int j=1;j<i-1;j++)
			se[i][j] = (se[i][j-1] + se[i-1][j])%MOD;
		if(i>1)
			se[i][i-1] = se[i][i-2];
	}
	for(int i=0;i!=2001;i++)
	{
		sl[0][i] = 1;
		for(int j=1;j<=i;j++)
		{
			sl[j][i] = sl[j-1][i];
			if(i-1 >= j) sl[j][i] += sl[j][i-1];
			sl[j][i]%=MOD;
		}
	}
	int T;
	cin >> T;
	for(int t=0;t!=T;t++)
	{
		int s1,s2;
		scanf("%d-%d",&s1,&s2);

		cout << "Case #" << t+1 << ": " << se[s1][s2] << " " << sl[s2][s2] << endl;
	}

	return 0;
}