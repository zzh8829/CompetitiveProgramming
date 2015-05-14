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
typedef pair<int,int> I2;

int a[40005];

int main()
{
	int k;
	cin >> k;
	int n = k/25;
	if(n*25 < k) n++;
	for(int i=0;i!=n+1;i++)
		a[i] = i%2?26:1;
	int d = n*25-k;
	if(n == 1)
	{
		a[1] -=d;
	} else {
		int m = d/2;
		a[1] -= m;
		if(a[n] == 1)
		{
			a[n] += d-2*m;
		} else {
			a[n] -= d-2*m;
		}
	}
	for(int i=0;i!=n+1;i++)
		cout << (char)(a[i]+'a'-1);
	cout << endl;
	return 0;
}