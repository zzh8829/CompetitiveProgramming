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

int prizes[] = {1,2,5,10,50,100,1000,10000,500000,1000000};
int amount[] = {0,0,0,0,0,0,0,0,0,0,0};

map<int,int> m;

string s;

int main()
{
	freopen("DATA12.txt","r",stdin);
	for(int i=0;i!=10;i++)
	{
		m[prizes[i]] = i;
	}
	for(int c=0;c!=10;c++)
	{
		memset(amount,0,sizeof(amount));
		int bk = 0;
		for(int i=0;i!=9;i++)
		{
			getline(cin,s);
			if(s[0]=='$')
			{
				amount[m[atoi(s.substr(1).c_str())]]++;
			} else {
				bk++;
			}
		}
		bool f = false;
		for(int i=0;i!=10;i++)
		{
			if(amount[i]+bk >= 3)
			{
				f = true;
				cout  << "$" <<  prizes[i] << " ";
			}
		}
		if(!f) {
			cout << "No Prizes Possible";
		}
		cout << endl;
	}
	return 0;
}