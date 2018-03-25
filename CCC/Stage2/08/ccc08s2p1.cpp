#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>

using namespace std;

struct Person
{
	Person(){
		next = -1;
		prev = -1;
	}
	string name;
	int loc;
	int dest;
	int next;
	int prev;
}p[101];

int gp[101],gpn,ingp[101];
int n,cnt;

bool cmp(const Person &a, const Person &b)
{
	return a.dest < b.dest;
}

void search(int i)
{
	if(ingp[i]) return;
	ingp[i]=1;
	for(int j=0;j!=n;j++)if(i!=j)
	{
		if(p[i].loc == p[j].dest)
		{
			p[i].next = j;
			p[j].prev = i;
			search(j);
			return;
		}
	}
}

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> p[i].name >> p[i].loc >> p[i].dest;
	for(int i=0;i!=n;i++)if(!ingp[i])
		search(i);
	for(int i=0;i!=n;i++)
		if(p[i].prev==-1)
			gp[gpn++]=i;
	for(int i=0;i!=gpn;i++)
	{
		int next = gp[i];
		while(next!=-1)
		{
			cnt ++;
			next = p[next].next;
		}
	}
	if(cnt!=n || gpn==0){
		cout << "Impossible" << endl;
		return 0;
	}
	for(int i=0;i!=gpn;i++)
	{
		int next = gp[i];
		while(next!=-1)
		{
			cout << p[next].name << endl;
			next = p[next].next;
		}
	}
	
	return 0;
}