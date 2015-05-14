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
#include <list>


using namespace std;

class GUMIAndSongsDiv2
{
public:
	vector<int> mDuration;
	vector<int> mTone;
	int mT;
	int mN;

	int d[16];
	int maxn ;
	int nt;
	int ot;

	int ok;

	list<int> li;
	list<int> l2;

	int maxSongs(vector <int> duration, vector <int> tone, int T)
	{
		mDuration = duration;
		mTone = tone;
		mT = T;
		maxn = 0;	
		nt = 0;
		mN = mDuration.size();
		ok = 0;
		memset(d,0,sizeof(d));

		for(int i=0;i!=mN;i++)if(!d[i])
		{
			d[i]=1;
			if(mDuration[i]<=mT)
			{
				nt = mTone[i];

			//	li.push_back(i);
			//	l2.push_back(mDuration[i]);
				rec(1,mDuration[i]);
			//	l2.pop_back();
			//	li.pop_back();
			}
			d[i]=0;
		}

		return maxn;
	}
	void rec(int n,int t)
	{
		if(n==mN)
		{
			ok = true;
			maxn = n;
			return;
		}
		if(n>maxn){
			/*
			for(list<int>::iterator it=li.begin();it!=li.end();it++)
			{
				cout << *it << " ";
			} cout << endl;
			for(list<int>::iterator it=l2.begin();it!=l2.end();it++)
			{
				cout << *it << " ";
			} cout << endl;
			cout << n << endl;
			cout << t << endl;
			*/
			maxn = n;
		}
		for(int i=0;i!=mN;i++)if(!d[i] && !ok)
		{
			d[i]=1;
			int newt = t+mDuration[i]+abs(nt-mTone[i]);
			if(newt<=mT)
			{
				ot = nt;
				nt = mTone[i];
			//	li.push_back(i);
			//	l2.push_back(newt);
				rec(n+1,newt);
			//	l2.pop_back();
			//	li.pop_back();
				nt = ot;
			} 
			d[i]=0;
		}
	}
};

typedef vector<int> vi;

int main()
{
	int ra[] = {5611,39996,20200,56574,81643,90131,33486,99568,48112,97168,5600,49145,73590,3979,94614};
	int ga[] = {2916,53353,64924,86481,44803,61254,99393,5993,40781,2174,67458,74263,69710,40044,80853};
	int t = 302606;
	vi du(ra,ra+sizeof(ra)/sizeof(int));
	vi tp(ga,ga+sizeof(ga)/sizeof(int));
	GUMIAndSongsDiv2 d;
	cout << d.maxSongs(du,tp,t) << endl;
	system("pause");
	return 0;
}