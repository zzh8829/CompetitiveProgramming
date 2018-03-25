#include <iostream>
#include <climits>
using namespace std;

int n;
int best = INT_MAX;
int h[1001];

int main()
{
#ifndef LOCAL
	freopen("skidesign.in","r",stdin);
	freopen("skidesign.out","w",stdout);
#endif
	cin >> n;
	for(int i=0;i!=n;i++)
		cin >> h[i];
	for(int i=17;i<=100;i++) // Highest
	{
		int t = 0;
		for(int j=0;j!=n;j++)
		{
			if(h[j]>i)
				t += (h[j]-i)*(h[j]-i);
			else if(i-17>h[j])
				t += (i-17-h[j])*(i-17-h[j]);
		}
		best = min(best,t);
	}
	cout << best << endl;
	return 0;
}
	