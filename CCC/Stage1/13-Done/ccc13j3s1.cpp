#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;


bool ok(int n)
{
	int digit[10]={0};
	while(n>0)
	{
		digit[n%10]++;
		if(digit[n%10]>1) return false;
		n/=10;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	while(true)
	{
		n++;
		if(ok(n))
		{
			cout << n << endl;
			break;
		}
	}	
	return 0;
}