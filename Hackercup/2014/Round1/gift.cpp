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
#include <climits>
#include <numeric>
using namespace std;

const int M = 140;
vector<int> age;
vector<int> vi;
vector<int> sel;
vector<int> ans;
bool ava[20*M+1];
int cp[M][M];
int T,N,K;
int minn;
int dif;

vector<int> vcp[M];
vector<int> vft[M];
vector<int> vpm;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int c = b;
		b = a%b;
		a = c;
	}
	return a;
}

bool ok(int a)
{
	for(int i=0;i!=sel.size();i++)
		if(!cp[sel[i]][a])
			return false;
	return true;
}

void rec(int idx,int tot,vector<char> vc)
{
	if(tot > minn) return;
	//cout << tot << " ";
	if(idx==N)
	{
		if(tot < minn)
		{
			//cout << tot << endl;
			
			ans = sel;
			
			for(int i=0;i!=ans.size();i++)
				cout << ans[i] <<" " ;
			cout << endl;
			

			minn = tot;
		}
		return;
	}
	vector<int>::iterator it = lower_bound(vcp[sel[idx-1]].begin(),vcp[sel[idx-1]].end(),age[idx]);
	for(;it!=vcp[sel[idx-1]].end();it++)
	{
		int n = *it;
		if(vc[n])continue;
		if(tot+n-age[idx] > minn) break;
		vector<char> nvc = vc;
		for(int j=0;j!=vft[n].size();j++)
			for(int k=1;vft[n][j]*k<M;k++)
				nvc[vft[n][j]*k]=1;
		sel.push_back(n);
		rec(idx+1,tot+n-age[idx],nvc);
		sel.pop_back();
	}
}

void rec2(int idx,vector<int> primes,int tot)
{
	if(tot>minn) return;
	if(idx==N)
	{
		if(tot < minn)
		{
			minn = tot;
			cout << tot << endl;
		}
		return;
	}
	int p = primes[0];
	if(p >= age[idx])
	{
		vector<int> np = primes;
		np.erase(np.begin());
		rec2(idx+1,np,tot+p-age[idx]);
	} else {
		vector<int>::iterator it = lower_bound(primes.begin(),primes.end(),age[idx]);
		for(int i=0;age[idx]+1 < M && age[idx]+i<=*it;i++)
		{
			int n = age[idx]+i;
			bool f2 = true;
			for(int j=0;j!=vft[n].size();j++)
			{
				if(!binary_search(primes.begin(),primes.end(),vft[n][j]))
				{
					f2 = false;
					break;
				}
			}
			if(f2)
			{
				vector<int> np = primes;
				for(int j=0;j!=vft[n].size();j++)
				{
					np.erase(lower_bound(np.begin(),np.end(),vft[n][j]));
				}
				rec2(idx+1,np,tot+n-age[idx]);
			}
		}
	}
}

int main()
{
	for(int i=0;i!=M;i++)
	for(int j=i;j!=M;j++)
	if(gcd(i,j)==1)
	{
		cp[i][j] = cp[j][i]=1;
		vcp[i].push_back(j);
		vcp[j].push_back(i);
	}
	for(int i=0;i!=M;i++)
		sort(vcp[i].begin(),vcp[i].end());
	for(int i=2;i!=M;i++)
	{
		int flag = true;
		for(int j=2;j<i;j++)
		if(i%j==0)
		{
			flag = false;
			break;
		}
		if(flag)
			vpm.push_back(i);
	}
	for(int i=0;i!=M;i++)
	for(int j=0;j!=vpm.size();j++)
	{
		if(i%vpm[j]==0)
			vft[i].push_back(vpm[j]);
	}
	cin >> T;
	for(int cs=1;cs<=T;cs++)
	{
		age.clear();
		vi.clear();
		sel.clear();
		ans.clear();
		dif = 0;
		minn = INT_MAX;
		cin >> N >> K;
		for(int i=0;i!=N;i++)
		{
			int t,t2;
			cin >> t;
			t2 = (t-1)/K * K + K;
			if(t==0) t2 = 0;
			dif += t2-t;
			age.push_back(t2/K);
		}
		sort(age.begin(),age.end());

		/*
		for(int i=0;i!=age.size();i++)
			cout << age[i] << " ";
		cout << endl;
		
		/*

		for(int i=0;i!=N;i++)
		{
			for(int j=0;j!=132;j++)
			{
				for(int k=0;k!=32;k++)
				{
					for(int v=32;v!=i;v--)
					{
						dp[i][j][k][v] = max(dp[k-1][v],dp[k-1][v-1]+1);
					}
				}
			}
		}
		*/
		bool f1 = 0;
		if(age[0]==1 || age[0]==0)
		{	
			f1 = 1;
			for(int i=1;i!=age.size();i++)
			{
				if(age[i]>1)
				{
					f1 = 0;
					break;
				}
			}
		} 
		if(f1)
		{
			minn = age.size()-accumulate(age.begin(),age.end(),0);
			if(age[0]==0)
				minn--; 
		} else {
#if 1
			int idx = 0;
			while(age[idx]==1 || age[idx]==0)
			{
				if(age[idx]==0)dif+=K;
				idx++;
			}
			vector<int> pl = vpm;
			rec2(idx,pl,0);
#else
			for(int i=age[0];i!=M && i < minn;i++)
			{
				//cout << i << " ";
				sel.push_back(i);
				vector<char> vc(M,0);
				for(int j=0;j!=vft[i].size();j++)
					for(int k=1;vft[i][j]*k<M;k++)
						vc[vft[i][j]*k]=1;
				rec(1,i-age[0],vc);
				sel.pop_back();
			}
#endif
		}
		

		//cout << accumulate(ans.begin(),ans.end(),0) << endl;
		//cout << accumulate(age.begin(),age.end(),0) << endl;
		

	//	cout << minn << " " << dif << endl;
		cout << "Case: " << cs << ": " << minn*K+dif << endl;
	}
	return 0;
}