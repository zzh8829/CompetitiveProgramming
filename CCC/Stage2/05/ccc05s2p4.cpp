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

int nums[10001];
int n,tn;
int cs;

int ps[10000];
int pn;
bool isprime(int n)
{
	if(n<2||!n&1)return false;
	for(int i=0;ps[i]*ps[i]<n+1;i++)
		if(n%ps[i]==0)
			return false;
	return true;
}

int main()
{
	ps[pn++]=2;
	for(int i=3;i<=10000;i+=2)
	{
		bool flag = true;
		for(int j=2;j*j<i+1;j++) 
			if(i%j==0)
		{
			flag = false;
			break;
		}
		if(flag) ps[pn++]=i;
	}
	cin >> cs;
	while(cs--)
	{
		cin >> n >> nums[0];
		for(int i=1;i!=n;i++)
		{
			cin >> tn;
			nums[i] = nums[i-1]+tn;
		}
		int sum,minn=999999,minb;
		for(int i=0;i!=n;i++)
		{
			for(int j=1;i+j!=n;j++)
			{
				if(!i) sum = nums[i+j];
				else sum = nums[i+j]-nums[i-1];
				if(isprime(sum))
				{
					if(j+1<minn)
					{
						minn = j+1;
						minb = i;
					}
				}
			}
		}
		if(minn==999999)
		{
			cout << "This sequence is anti-primed." << endl;
		} else {
			cout << "Shortest primed subsequence is length " << minn <<":";
			for(int i=minb;i<minb+minn;i++)
			{
				cout << " ";
				if(!i)
					cout << nums[i];
				else
					cout << nums[i]-nums[i-1];
			}
			cout << endl;
		}

	}
	return 0;
}