#include <iostream>
#include <algorithm>
using namespace std;

int house[1001];
int n,k;
int LEN = 1000000;

int place(int len)
{
	int best = n;
	int d = len*2;
	int i = 0;
	while(i<n && house[i] <= house[0]+d)
	{
		int cnt = 1;
		int end = house[i];
		int j = i+1;
		while(j<n && house[i] >(house[j]+d-LEN))
		{
			if(house[j]>end)
			{
				cnt++;
				end = house[j]+d;
			}
			j++;
		}
		best = min(best,cnt);
		i++;
	}
	return best;
}

int main()
{
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> house[i];
	sort(house,house+n);
	cin >> k;
	int low = -1;
	int high = LEN;
	while(high > (low+1))
	{
		int mid = (low+high)/2;
		if(place(mid) > k)
		{
			low = mid;
		} else {
			high = mid;
		}
	}
	cout << high << endl;
}