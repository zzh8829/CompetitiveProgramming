#include <iostream>
using namespace std;

int m[110],n;

bool ok(int b)
{
	int x = n,len = 0;
	while(x!=0) {
		m[len++] = x%b;
		x/=b;
	}
	for(int i=0;i!=len/2;i++)
		if(m[i]!=m[len-i-1])
			return false;
	return true;
}

int main()
{
	cin >> n;
	for(int i=2;i< 31622 && i<n;i++)
		if(ok(i)) cout << i << endl;
	if(n > 31622)
		for(int i= n/31622 ;i!=0;i--)
			if(n%i==0) cout << n/i-1 << endl;
	return 0;
}