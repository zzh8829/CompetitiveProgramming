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

char str[100001];
int freq[256];

int main()
{
	int n;
	cin >> n;
	scanf("%s",str);
	int maxi=0;
	for(int i=0;i!=n;i++)
	{
		freq[str[i]]++;
		if(freq[str[i]] > maxi)
		{
			maxi = freq[str[i]];
		}
	}
	int maxn = 0;
	for(int i=0;i!=256;i++)
	{
		if(freq[i]==maxi)
			maxn++;
	}
	long long ans = 1;
	for(int i=0;i!=n;i++)
	{
		ans *= maxn;
		ans %= 1000000007;
	}
	cout << ans << endl;
	return 0;
}