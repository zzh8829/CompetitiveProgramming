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

typedef map<string,int> MSI;
typedef multimap<int,string>  MIS; 

int cs,n,k;
string ts;

int main()
{
	cin >> cs;
	while(cs--)
	{
		cin >> n >> k;
		MSI msi;
		MIS mis;
		for(int i=0;i!=n;i++)
		{
			cin >> ts;
			msi[ts]++;
		}
		for(MSI::iterator it = msi.begin();it!=msi.end();it++)
		{
			mis.insert(make_pair(it->second,it->first));
		}
		cout<< k;
		string ord;
		if(k==1)
			ord = "st";
		else if((k%(100))==11)
			ord = "th";
		else if(k%10==1)
			ord = "st";
		else if(k%10==2)
			ord = "nd";
		else if(k==3)
			ord = "rd";
		else 
			ord = "th";
		printf("%s most common word(s):\n",ord.c_str());
		if(k <= mis.size())
		{
			MIS::iterator it = mis.end();
			advance(it,-k);
			MIS::iterator it2 = it;
			it2++;
			if(it2==mis.end() || it2->first != it->first)
			{
				it2--;
				while(true)
				{
					cout << it->second << endl;
					if(it==mis.begin())break;
					it2--;
					if(it->first != it2->first)break;
					it--;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
