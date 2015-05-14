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

typedef long long LL;

LL dn(LL n)
{
	LL ret = 0;
	while(n)
	{
		ret += n%10;
		n/=10;
	}
	return ret;
}

LL rec(LL n)
{
	if(n < 10)
		return n*(n-1)/2;
	return rec(n%10) + 45*(n/10) + (n%10)*dn(n/10) + 10*rec(n/10);
}

int main()
{
	int cc;
	cin >> cc;
	for(int c=0;c!=cc;c++)
	{
		LL a,b;
		cin >> a >> b;
		cout << rec(b+1) - rec(a) << endl;
	}
	return 0;
}
