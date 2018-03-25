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

int n,m;

int na[100005];
int ma[100005];
long long nc[100005];
long long mc[100005];

long long go(int a) {
	int idx = lower_bound(na,na+n,a) - na;
	long long sum = idx==0?0:(a*(idx+1)-nc[idx]);
	cout << idx << " " << sum << endl;
	idx = upper_bound(ma,ma+m,a) - ma;
	sum += mc[idx] - a * (m-idx);
	return sum;
}

int main()
{
	freopen("D.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=0;i!=n;i++) {
		scanf("%d",na+i);
	}
	for(int i=0;i!=m;i++) {
		scanf("%d",ma+i);
	}
	sort(na,na+n); // 1 2 3 4 5
	sort(ma,ma+m); // 6 7 8 9 10
	for(int i=0;i!=n;i++) {
		nc[i] = na[i];
		if(i) nc[i] += nc[i-1];
	}
	for(int i=m-1;i>=0;i--) {
		mc[i] = ma[i];
		if(i!=m-1) mc[i] += mc[i+1];
	}
	for(int i=0;i!=n;i++) {
		cout << nc[i] << " ";
	}
	cout << endl;
	for(int i=0;i!=m;i++) {
		cout << mc[i] << " ";
	}
	cout << endl;
	cout << go(6);

	return 0;
}