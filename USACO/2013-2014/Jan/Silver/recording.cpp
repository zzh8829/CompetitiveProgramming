#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>
#include <tr1/unordered_map>
using namespace std;
using namespace std::tr1;

typedef pair<int,int> I2;

int n;
vector<I2> vt;

int cnt = 0;
bool sel[151];

bool cmp(I2 a,I2 b)
{
	return a.second == b.second?a.first<b.first:a.second<b.second;
}

int findBest(int end)
{
	int i=n-1;
	for(;i>=0;i--)if(!sel[i])
		if(vt[i].second <= end)
			break;
	if(i==-1)return -1;
	int ti = i;
	int j=0;
	for(;j!=n;j++)if(!sel[j])
		if(vt[j].first > vt[ti].first && vt[j].second <=vt[i].second)
			ti=j;
	i = ti;
	//cout << "best " << end << " is " << i << " [" << vt[i].first << ", " << vt[i].second << "]\n";
	return i;
}

int main()
{
#ifndef LOCAL1
	freopen("recording.in","r",stdin);
	freopen("recording.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		int a,b;
		cin >> a >> b;
		vt.push_back(I2(a,b));
	}
	sort(vt.begin(),vt.end(),cmp);

//	for(int i=0;i!=n;i++)
//		cout << vt[i].first << " " << vt[i].second << endl;


	int end1 = vt[n-1].second;
	int end2 = vt[n-1].second;
	while(true)
	{
		int i1 = findBest(end1);
		if(i1!=-1)
		{
			end1 = vt[i1].first;
			sel[i1] = true;
			cnt++;
		} else break;
	}
	while(true)
	{
		int i2 = findBest(end2);
		if(i2!=-1)
		{
			end2 = vt[i2].first;
			sel[i2] = true;
			cnt++;
		} else break;
	}

	int cnt1 = cnt;

	cnt=0;
	memset(sel,0,sizeof(sel));
	end1 = vt[n-1].second;
	end2 = vt[n-1].second;
	while(true)
	{
		int i1 = findBest(end1);
		if(i1!=-1)
		{
			end1 = vt[i1].first;
			sel[i1] = true;
			cnt++;
		}	
		int i2 = findBest(end2);
		if(i2!=-1)
		{
			end2 = vt[i2].first;
			sel[i2] = true;
			cnt++;
		}
		if(i1==-1 && i2==-1) break;
	}
	int cnt2 = cnt;
	cout << max(cnt1,cnt2) << endl;
	return 0;
}
