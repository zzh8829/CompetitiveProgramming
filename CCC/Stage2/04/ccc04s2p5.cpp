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

using namespace std;

int m[70][3];
int n;
int main()
{
	for(int i=1;i<=18;i++)
		for(int j=0;j!=3;j++)
			m[i][j]=1;
	cin >> n;

	int rl,pl;
	char rb,pb;
	for(int i=0;i!=n;i++)
	{
		cin >> rl >> rb >> pl >> pb;
		m[rl][rb-'A']=0;
		if(!m[rl][1] && (!m[rl][0]||!m[rl][2]))
		{
			cout << "The tower collapses after removing " << rl << rb << endl;
			return 0;
		}
		m[pl][pb-'A']=1;
	}
	cout << "The tower never collapses" << endl;	
	return 0;
}