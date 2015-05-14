#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

map<string,int> spam,nonspam,msg;

double check(map<string,int> f1,map<string,int> f2)
{
	double top = 0;
	double bot1 = 0;
	double bot2 = 0;
	for (map<string,int>::iterator it=f1.begin(); it!=f1.end(); ++it)
    {
    	top+= it->second*f2[it->first];
    	bot1+= it->second*it->second;
    }	
    for (map<string,int>::iterator it=f2.begin(); it!=f2.end(); ++it)
    	bot2+= it->second*it->second;
	return top/sqrt(bot1)/sqrt(bot2);
}

int main()
{
	int sn,nn,mn;
	cin >> sn >> nn >> mn ;
	string str;
	for(int c=0;c!=sn;c++)
		while(getline(cin,str) && str!="ENDMESSAGE")
			if(str.size()>=3)
				for(int i=0;i!=str.size()-2;i++)
					spam[str.substr(i,3)]++;
	for(int c=0;c!=nn;c++)
		while(getline(cin,str) && str!="ENDMESSAGE")
			if(str.size()>=3)
				for(int i=0;i!=str.size()-2;i++)
					nonspam[str.substr(i,3)]++;
	for(int c=0;c!=mn;c++)
	{
		msg.clear();
		while(getline(cin,str) && str!="ENDMESSAGE")
			if(str.size()>=3)
				for(int i=0;i!=str.size()-2;i++)
					msg[str.substr(i,3)]++;
		double f1 = check(msg,spam);
		double f2 = check(msg,nonspam);
		printf("%.5f %.5f\n",f1,f2);
		printf("%s\n",f1>f2?"spam":"non-spam");
	}	
	return 0;
}