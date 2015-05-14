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

int main()
{
	freopen("hold.in","r",stdin);
	freopen("hold.out","w",stdout);
	int T;
	cin >> T;
	for(int cs=1;cs<=T;cs++)
	{
		int N,H;
		cin >> N >> H;
		for(int i=0;i!=H;i++)
		{
			int a,b;
			cin >> a >> b;
		}
		cout << "Case #" << cs << ": ";
		for(int i=0;i!=H;i++)
		{
			cout << "BF"[rand()%2];
		}
		cout << endl;
	}
	return 0;
}