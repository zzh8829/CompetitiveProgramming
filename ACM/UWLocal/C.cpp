#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
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
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define rint(x) scanf("%d", &(x))
#define rll(x) scanf("%lld", &(x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

LL hs[20005];
LL ks[20005];

int main()
{
    int n,m;
    while(true)
    {
        rint(n);rint(m);
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; i++)
        {
            rll(hs[i]);
        }
        for(int i = 0; i < m; i++)
        {
            rll(ks[i]);
        }
        sort(hs,hs+n);
        sort(ks,ks+m);
        int kn = 0;
        LL tot = 0;
        int f = false;
        for(int i = 0;i < n; i++)
        {
            while(kn < m && ks[kn] < hs[i]) kn++;
            if(kn == m)
            {
                f = true;
                break;
            } 
            tot += ks[kn];
            kn++;
        }
        if(f)
        {
            cout << "Loowater is doomed!" << endl;
        } else {
            cout << tot << endl;
        }
    }
    return 0;
}
