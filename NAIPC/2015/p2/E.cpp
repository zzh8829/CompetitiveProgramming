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

int hs[100005];
int n;

int main()
{
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	{
		scanf("%d",&hs[i]);;
	}
	sort(hs,hs+n);
	int minn = n;
	for(int i=0;i!=n;i++)
	{
		minn = min(hs[i] + n-i-1,minn);
	}
	cout << minn << endl;

	return 0;
}