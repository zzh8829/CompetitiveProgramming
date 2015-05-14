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

int b[51];

int main()
{
	int cc;
	cin >> cc;
	for(int c=0;c!=cc;c++)
	{
		int n;
		cin >> n;
		for(int i=0;i!=n;i++)
			cin >> b[i];
		s = 1;
		while(s!=n)
		{
			if(b[s] > b[s-1])
			{
				s++;
				continue;
			}
		}
	}
	return 0;
}