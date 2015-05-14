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

typedef long long LL;

int main()
{
	//freopen("1.txt","r",stdin);
	//freopen("1.out","w",stdout);
	int cs;
	cin >> cs;
	for(int cc=1;cc<=cs;cc++)
	{
		string lt;
		cin >> lt;
		LL n;
		cin >> n;
		string ans = "";
		int s = lt.size();
		while(n>0)
		{
			int idx = n%s;
			ans = lt[(idx+s-1)%s] + ans;
			n = (n-1)/s;
		}
		cout << "Case #" << cc << ": " << ans << endl;
	}
	return 0;
}