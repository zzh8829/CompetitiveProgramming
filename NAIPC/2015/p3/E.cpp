#include <iostream>
#include <cmath>

using namespace std;


void cyclic_roll(int &a, int &b, int &c, int &d)
{
	int temp = a;
	a = b;
	b = c;
	c = d;
	d = temp;
}

int m[101][101];

int main()
{
	int n;
	cin >> n;
	for(int i=0;i!=n;i++)
	{
		string s;
		cin >> s;
		int w = sqrt(s.size());
		for(int i=0;i!=w;i++)
		for(int j=0;j!=w;j++)
				m[i][j] = s[i*w+j];
		for(int i=0; i<w/2; i++)
			for(int j=0; j<(w+1)/2; j++)
				cyclic_roll(m[i][j], m[w-1-j][i], m[w-1-i][w-1-j], m[j][w-1-i]);
		for(int i=0; i<w/2; i++)
			for(int j=0; j<(w+1)/2; j++)
				cyclic_roll(m[i][j], m[w-1-j][i], m[w-1-i][w-1-j], m[j][w-1-i]);
		for(int i=0; i<w/2; i++)
			for(int j=0; j<(w+1)/2; j++)
				cyclic_roll(m[i][j], m[w-1-j][i], m[w-1-i][w-1-j], m[j][w-1-i]);
		for(int i=0;i!=w;i++)
		for(int j=0;j!=w;j++)
				cout << (char)m[i][j];
		cout << endl;
	}
}