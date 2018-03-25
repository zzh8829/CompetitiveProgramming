#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>

using namespace std;

char m[51][51];
int R,C;
int cs,n;
string str;

int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

bool ok(int r,int c)
{
	int tr,tc;
	for(int i=0;i!=8;i++)
	{
		bool flag = true;
		for(int j=0;j!=str.size();j++)
		{
			tr = r+ j*dr[i];
			tc = c+ j*dc[i];
			if(tr<1 || tc<1 || tr>R || tc>C || m[tr][tc]!=str[j])
			{
				flag = false;
				break;
			}
		}
		if(flag)return true;
	}
	return false;
}

int main()
{
	cin >> cs;
	while(cs--)
	{
		cin >> R >> C;
		for(int i=1;i<=R;i++)
		{
			cin >> str;
			for(int j=0;j!=str.size();j++)m[i][j+1]=tolower(str[j]);
		}
		cin >> n;
		for(int w=0;w!=n;w++)
		{
			cin >> str;
			for(int i=0;i!=str.size();i++)str[i]=tolower(str[i]);
			bool flag = true;
			for(int i=1;i<=R && flag;i++)
			for(int j=1;j<=C && flag;j++)
			{
				if(ok(i,j))
				{
					printf("%d %d\n",i,j);
					flag = false;
				}
			}
		}
		printf("\n");
	}
	return 0;
}