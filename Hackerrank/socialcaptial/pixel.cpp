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

#define rint(x) scanf("%d", &(x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

string str[] = {
    "Black","White","Red","Green","Blue"
};

int dis(int a,int b,int c,int x,int y,int z)
{
    return (a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int tt=0;tt<n;tt++)
    {
        int r=0,g=0,b=0;
        char c;
        for(int i=0;i!=8;i++)
        {
            cin >> c;
            r = r*2+(c=='1'?1:0);
        }
        for(int i=0;i!=8;i++)
        {
            cin >> c;
            g = g*2+(c=='1'?1:0);
        }
        for(int i=0;i!=8;i++)
        {
            cin >> c;
            b = b*2+(c=='1'?1:0);
        }
        vector<I2> vi;
        vi.push_back(I2(dis(0,0,0,r,g,b),0));
        vi.push_back(I2(dis(255,255,255,r,g,b),1));
        vi.push_back(I2(dis(255,0,0,r,g,b),2));
        vi.push_back(I2(dis(0,255,0,r,g,b),3));
        vi.push_back(I2(dis(0,0,255,r,g,b),4));
        sort(vi.begin(),vi.end());
        if(vi[0].first == vi[1].first)
        {
            cout << "Ambiguous" << endl;
        } else {
            cout << str[vi[0].second] << endl;
        }
    }

    return 0;
}
