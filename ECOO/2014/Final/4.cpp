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
int dp[2005];

bool isBabyTalk(string word)
{
	if (word.size()%2!=0) return false;
	return word.substr(0,word.size()/2)==word.substr(word.size()/2);
}

int main()
{
	freopen("DATA41.txt","r",stdin);

	for(int cs=0;cs!=10;cs++) {

		memset(dp,0,sizeof(dp));

	string word;
	cin >> word;
	int best=0;

	for (int i=0;i<word.size();i++)
	{
		for (int s=1;s<=word.size()-i;s++)
		{
			//cout << i << " " << s << endl;
			//cout << word.substr(i,s) << endl;
			if (isBabyTalk(word.substr(i,s)))
			{
				dp[i+s] = max(dp[i+s],dp[i]+s);
				best = max(best,dp[i+s]);
			}
		}
	}
	//for(int i=0;i!=word.size();i++)
//		cout << dp[i] << " ";//
	//cout << endl;
	cout << best << endl;

	}
	return 0;
}