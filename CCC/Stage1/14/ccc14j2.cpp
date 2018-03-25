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
	string str;
	getline(cin,str);
	getline(cin,str);
	int a = 0;
	int b = 0;
	for(int i=0;i!=str.size();i++)
	{
		if(str[i]=='A')
			a++;
		if(str[i]=='B')
			b++;
	}
	if( a > b)
	{
		cout << "A" << endl;
	} else if(a  < b)
	{
		cout << "B" << endl;
	} else 
	cout << "Tie" << endl;
	
	return 0;
}