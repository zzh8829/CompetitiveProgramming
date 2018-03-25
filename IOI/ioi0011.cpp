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
#include <algorithm>
using namespace std;

// Longest Common Subsequence LCS

int dpp[2][5001];
int n,maxL;

int main()
{
	string a;
	cin >> n >> a;
	int* dp = dpp[0];
	int* dp2 = dpp[1];
	for(int i=0;i!=n;i++)
	{
		for(int j=0;j!=n;j++)
		{
			if(a[i]==a[n-j-1])
			{
				dp2[j] = ((i&&j)?dp[j-1]:0)+1;
				maxL = max(maxL,dp2[j]);
			}
			else
				dp2[j] = max(i?dp[j]:0,j?dp2[j-1]:0);
		}
		swap(dp,dp2);
	}
	cout << n-maxL << endl;
	return 0;
}