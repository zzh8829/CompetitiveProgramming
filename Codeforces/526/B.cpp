#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define Fx(x, n) for (int x = 0; x < (n); x++)
#define Fi(n) Fx(i, n)
#define Fj(n) Fx(j, n)
#define Fij(ni, nj) Fi(ni) Fj(nj)
#define Frx(x, n) for (int x = (n)-1; x >= 0; x--)
#define Fri(n) Frx(i, n)
#define Frj(n) Frx(j, n)
#define Fitx(x, xs) for (auto x = xs.begin(); x!=xs.end(); x++)
#define Fit(xs) Fitx(it, xs)
#define Fritx(x, xs) for (auto x = xs.rbegin(); x!=xs.rend(); x++)
#define Frit(xs) Fritx(it, xs)
#define Fe(x, xs) for (auto& x : (xs))
#define Ri(x) scanf("%d", &(x))
#define Rf(x) scanf("%lf", &(x))

typedef long long LL;
typedef pair<int,int> I2;

int n;
int a[2050];
int g[2050][2050];

LL tot;

int mpow[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096};

int main()
{

	Ri(n);
	Fi(mpow[n+1]-2) Ri(a[i+2]);
	for(int i=n;i>0;i--)
	{
		for(int j=0;j<mpow[i]/2;j++)
		{
			//cout << a[mpow[i] + j*2] << " " << a[mpow[i] + j*2+1] << " ";
			a[mpow[i]/2 + j] += max(a[mpow[i] + j*2],a[mpow[i] + j*2+1]);
			tot += abs(a[mpow[i] + j*2]-a[mpow[i] + j*2+1]);
		}
		//cout << endl;
	}
	cout << tot << endl;
///	cout << a[1] << endl;
	return 0;
}