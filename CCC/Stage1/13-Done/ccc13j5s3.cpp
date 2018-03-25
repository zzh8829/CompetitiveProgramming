#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef vector<int> S;

bool isWin(int n,S s)
{
	int ts = s[n];
	for(int i=1;i<=4;i++) if (i!=n)
	{
		if(ts<=s[i]) return false;
	}
	return true;
}

bool done[5][5];

int win = 0;
int t,n;

void dfs(int a,int b,S s)
{
	if(a==4)
	{
		if(isWin(t,s)) win++;
		return;
	}
	int na = a;
	int nb = b;
	if(nb==4){
		nb=na+2;
		na++;
	} else {
		nb++;
	}
	if(done[a][b])
	{		
		dfs(na,nb,s);
	}
	else
	{
		// a win
		S s1 = s;
		s1[a]+=3;
		dfs(na,nb,s1);
		// b win
		S s2 = s;
		s2[b]+=3;
		dfs(na,nb,s2);
		// tie
		S s3 = s;
		s3[a]+=1;
		s3[b]+=1;
		dfs(na,nb,s3);
		
	}

}

int main()
{
	cin >> t >> n;
	int a,b;
	int sa,sb;
	S s;
	for(int i=0;i!=5;i++)
		s.push_back(0);
	for(int i=0;i!=n;i++)
	{
		cin >> a >> b >> sa >> sb;
		if(sa>sb)
			s[a]+=3;
		else if (sa<sb)
			s[b]+=3;
		else{
			s[a]+=1;
			s[b]+=1;
		}
		done[a][b]=true;
	}
	dfs(1,2,s); 
	cout << win << endl;
	return 0;
}