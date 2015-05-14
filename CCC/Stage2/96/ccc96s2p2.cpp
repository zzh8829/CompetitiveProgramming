#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int cs,n;
int g[10000];

void update(string input,int c1,int c2)
{
	int s1,s2;
	for(int i=0;i<=9999;i++) if(!g[i])
	{
		s1 = 0,s2 = 0;
		ostringstream ss;
		ss << setw(4) << setfill('0') << i;
		string ans = ss.str();

		string buf = ans;
		string num = input;
		for(int j=0;j!=4;j++)
		{
			if(num[j]==buf[j])
			{
				s1++;
				num[j] = '!';
				buf[j] = '@';
			}
		}
		for(int j=0;j!=4;j++)
		{
			for(int k=0;k!=4;k++)
			{
				if(num[j]==buf[k])
				{
					s2++;
					num[j] = '!';
					buf[k] = '@';
					break;
				}
			}
		}
		if(c1!=s1 || c2!=s2) g[i] = 1;
	}
}

int main()
{
	cin >> cs;
	while(cs--)
	{
		cin >> n;
		memset(g,0,sizeof(g));
		for(int i=0;i!=n;i++)
		{
			string num,guess;
			cin >> num >> guess;
			update(num,guess[0]-'0',guess[2]-'0');
		}
		int na = 0;
		int ans = -1;
		for(int i=0;i<=9999;i++)
		{
			if(!g[i])
			{
				ans = i;
				na++;
			}
		}
		if(na==1)
		{
			cout << setw(4) << setfill('0') << ans << endl;
		} else if(na==0)
		{
			cout << "impossible\n";
		} else 
		{
			cout << "indeterminate\n";
		}
	}
}