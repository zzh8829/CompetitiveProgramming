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

int l[21][3];

int main()
{
	int cc;
	cin >> cc;
	for(int t=0;t!=cc;t++)
	{
		int P,C,F;
		cin >> P >> C >> F;
		int n;
		cin >> n;
		for(int i=0;i!=n;i++)
		{
			cin >> l[i][0] >> l[i][1] >> l[i][2];
		}
		string an = "no";
		for(int i=0;i!=pow(2,n);i++)
		{
			bitset<20> bs(i);
			int p=0,c=0,f=0;
			for(int j=0;j!=n;j++)
			{
				if(bs[j])
				{
					p += l[j][0];
					c += l[j][1];
					f += l[j][2];
				}
			}
			if(p==P && c==C && f==F)
			{
				an = "yes";
				break;
			}
		}
		cout << "Case #" << t+1 <<": " << an << endl;

	}
	return 0;
}