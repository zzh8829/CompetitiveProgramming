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
#include <stack>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int C=0;C!=T;C++)
	{
		int n;
		scanf("%d",&n);
		stack<int> sa;
		for(int i=0;i!=n;i++)
		{
			int t;
			cin >> t;
			sa.push(t);
		}
		stack<int> sb;
		int cur=1;

		bool flag = true;
		while(cur<=n)
		{
			if(!sa.empty())
			{
				if(sa.top() != cur) 
				{
					if(!sb.empty() && sb.top()==cur)
					{
						sb.pop();
						cur++;						
						continue;
					} else {
						while(!sa.empty() && sa.top() != cur) {
							sb.push(sa.top());
							sa.pop();
						}
						if(sa.empty())
						{
							flag = false;
							break;
						}
						sa.pop();
						cur++;
						continue;
					}
				} else {
					sa.pop();
					cur++;
					continue;
				}
			}
			if(sb.empty() || sb.top() != cur)
				flag = false;
			sb.pop();
			cur++;
		}
		if(flag)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
	
	return 0;
}