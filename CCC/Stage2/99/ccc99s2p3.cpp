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

char o[101][101];
int n,k;
int R1,R2,C1,C2;

char rec(char ch,int r,int c,int m)
{
	if(m==0) return ch;
	char t = o[r%n][c%n];
	if(t=='.') ch = ' ';
	if(t=='!') ch = '*';
	if(r==0 && c==0) return ch;
	return rec(ch,r/n,c/n,m-1);
}

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
	for(int j=0;j!=n;j++)
		cin >> o[n-i-1][j];
	while(cin >> k && k!=-1)
	{
		cin >> R1 >> R2 >> C1 >> C2;
		R1--;R2--;C1--;C2--;
		for(int i=R2;i>=R1;i--)
		{
			for(int j=C1;j<=C2;j++)
			{
				if(j!=C1)cout << " ";
				cout << rec('*',i,j,k);
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}