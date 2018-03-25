#include <iostream>
#include <algorithm>
using namespace std;

int c[101];
int t;

int main()
{
	cin >> t;
	int n;
	cin >> n;
	for(int i=0;i!=n;i++) cin >> c[i];
	sort(c,c+n);
	int sum = 0;
	int cnt = 0;
	for(int i=0;i!=n;i++)
	{
		if(sum+c[i] <= t)
		{
			cnt++;
			sum+=c[i];
		}
		else
		break;
	}
	cout << cnt << endl;
	return 0;
}