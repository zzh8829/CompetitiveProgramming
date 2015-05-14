#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=0;t!=T;t++)
	{
		set<string> ss;
		int N;
		cin >> N;
		int ans = 0;
		for(int i=0;i!=N;i++)
		{
			string word;
			cin >> word;
			ss.insert(word);
			set<string>::iterator it = ss.find(word);
			int pn,nn;
			pn = nn = 1;
			if(it != ss.begin())
			{
				string pw = *(--it);
				for(int i=0;i!=min(word.size(),pw.size());i++)
				{
					if(word[i] == pw[i])
						pn += 1;
					else
						break;
				}
				it++;
			}
			if((++it) != ss.end())
			{
				string nw = *it;
				for(int i=0;i!=min(word.size(),nw.size());i++)
				{
					if(word[i] == nw[i])
						nn += 1;
					else
						break;
				}
			}
			//cout << pn <<  " " << nn << endl;
			ans += min((int)word.size(),max(pn,nn));
		}
		cout << "Case #" << t+1 << ": " << ans << endl;
	}

	return 0;
}