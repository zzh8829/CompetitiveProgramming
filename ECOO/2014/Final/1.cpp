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

map<char,int> im;
string cm = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,?";

char dec(char c,int k)
{
	return cm[((im[c]+1)*k)%67-1];
}

int main()
{
	freopen("DATA11.txt","r",stdin);
	//cout << cm.size() << endl;

	for(int i=0;i!=cm.size();i++)
		im[cm[i]] = i;

	for(int cs=0;cs!=10;cs++)
	{
		string org,enc,msg;
		getline(cin,org);
		getline(cin,enc);
		getline(cin,msg);

	//	cout << org << endl << enc << endl << msg << endl;

		int key = 0;
		for(int i=2;i<=66;i++)
		{
			bool f = true;
			for(int j=1;j!=org.size()-1;j++)
			{
	//			cout << enc[j] << " " << dec(enc[j],i) << " " << org[j] << endl;
				if(dec(enc[j],i) != org[j])
				{
	//				cout << "WTF" << endl;
					f = false;
					break;
				}
			}
	//		cout << endl;
			if(f)
			{
				key = i;
				break;
			}
		}
	//	cout << key << endl;
		cout << "*";
		for(int i=1;i!=msg.size()-1;i++)
		{
			cout << dec(msg[i],key);
		}
		cout << "*";
		cout << endl;

	}

	return 0;
}
