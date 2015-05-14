#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
using namespace std;

vector<int> vi;
int maxv;
int n;
int main()
{
	cin >> maxv >> n;
	int v;
	for(int i=0;i!=n;i++)
	{
		cin >> v;
		vi.push_back(v);
	}
	int sum = 0;
	for(int i=0;i!=n;i++)
	{
		sum+=vi[i];
		if(sum>maxv)
		{
			cout << i << endl;
			return 0;
		}
		if(i>=3)
		{
			sum-=vi[i-3];
		}
	}
	cout << n << endl;	
	return 0;
}