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

int n;

int main()
{
	cin >> n;
	int k = n/2;
	for(int i=k;i>=0;i--)
	{
		for(int j=0;j!=i;j++)
			cout << "*";
		for(int j=i;j!=n-i;j++)
			cout << "D";
		for(int j=n-i;j!=n;j++)
			cout << "*";
		cout << endl;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j!=i;j++)
			cout << "*";
		for(int j=i;j!=n-i;j++)
			cout << "D";
		for(int j=n-i;j!=n;j++)
			cout << "*";
		cout << endl;
	}
	return 0;
}