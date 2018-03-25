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

int main()
{
    int n,m;
    while(cin >> n && cin >> m && (n!=0 && m!=0))
    {
        if(n == 1)
        {
            if(m == 1)
            {
                cout << endl;
            } else {
                cout << "ERROR" << endl;
            }
            break;
        }
        string ans = "E";
        int sn = 0;
        int en = 1;
        int x = 2*n-2;
        int c = 1;
        for(int i = 0;i!=x;i++)
        {
            if(c*2 > M)
            {
                ans = "S" + ans;
                sn++;
            } else {

            }
        }
        
EEESSS
EESESS
EESSES
ESEESS
ESESES
    }
    return 0;
}
