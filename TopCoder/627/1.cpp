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

struct ManySquares
{
	int howManySquares(vector<int> sticks)
	{
		int m[1001]={0};
		for(int i=0;i!=sticks.size();i++)
			m[sticks[i]++];
		int cnt = 0;
		for(int i=1;i<=1000;i++)
		{
			cnt += m[i]/4;
		}
		return cnt;
	}
};
