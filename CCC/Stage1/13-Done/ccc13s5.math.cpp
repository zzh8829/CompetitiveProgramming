#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n,cost = 0;
	cin >> n;
	while(n!=1)
	{
		int i=2;
		int mx = sqrt(n)+1;
		for(;i!=mx;i++)if(n%i==0)break;
		if(i==mx)
			cost += --n;
		else {
			cost += i-1;
			n = n- n/i;
		}
	}
	cout << cost << endl;
	return 0;
}