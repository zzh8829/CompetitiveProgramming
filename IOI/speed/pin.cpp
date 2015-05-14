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

int N,D;

struct P
{
	int a[4];
	P(){}
	P(char* s){
		for(int i=0;i!=4;i++)
		{
			if(!isdigit(s[i]))
				s[i] = s[i]-'a'+'0'+10;
			a[i]=s[i]-'0';
		}
	}
	int& operator[](int i){return a[i];}
};

P ps[50001];

int dif(int a,int b)
{
	int cnt = 0;
	for(int i=0;i!=4;i++)
		if(ps[a][i]!=ps[b][i])
			cnt++;
	return cnt;
}

int main()
{
	scanf("%d%d",&N,&D);
	for(int i=0;i!=N;i++)
	{
		char s[4];
		scanf("%s",s);
		ps[i] = P(s);
	}	
	int cnt = 0;
	for(int i=0;i!=N;i++)
		for(int j=i+1;j!=N;j++)
			if(dif(i,j)==D)
				cnt++;
	cout << cnt << endl;
	return 0;
}