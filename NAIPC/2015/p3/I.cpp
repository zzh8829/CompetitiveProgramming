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
#include <fstream>
#include <functional>
#include <iostream>
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

using namespace std;

int main()
{
	int cc;
	cin >> cc;
	for(int c=0;c!=cc;c++)
	{
		string s;
		int n;
		cin >> s;
		cin >> n;
		char jk;
		deque<int> dq;
		cin >> jk;
		for(int i=0;i!=n;i++)
		{
			if(i)
				cin >> jk;
			int a;
			cin >> a;
			dq.push_back(a);
		}
		cin >> jk;
		int o = 0;
		for(int i=0;i!=s.size();i++)
		{
			if(s[i]=='R')
				o = 1-o;
			if(s[i]=='D')
			{
				if(dq.size() == 0)
				{
					cout << "error" << endl;
					o = 2;
					break;
				}
				if(o == 0)
				{
					dq.pop_front();
				}
				if(o == 1)
				{
					dq.pop_back();
				}
			}
		}
		if(o==0)
		{
			cout << "[";
			for(int i=0;i!=dq.size();i++)
			{
				if(i)
					cout << ",";
				cout << dq[i];
			}
			cout << "]" << endl;
		}
		if(o==1)
		{
			cout << "[";
			for(int i=dq.size()-1;i!=-1;i--)
			{
				if(i!=dq.size()-1)
					cout << ",";
				cout << dq[i];
			}
			cout << "]" << endl;
		}
	}
	return 0;
}