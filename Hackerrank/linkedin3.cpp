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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K,L,M;
    string s;
    cin >> N >> K >> L >> M;
    cin >> s;

    unordered_map<string, int> msi;

    for(int i = 0; i < N; i++)
    {
        set<char> si;
        for(int j = 1; j <= L && i + j - 1 < N; j++)
        {
            si.insert(s[i + j - 1]);
            if(si.size() > M) break;

            if(j >= K)
            {
                string ss(&s[i], j);
                if(!msi.count(ss))
                    msi[ss] = 0;
                msi[ss] += 1;
            }
        }
    }

    int maxi=0;
    for(auto& kv : msi)
    {
        //cout << kv.first << ": " << kv.second << endl;
        maxi = max(maxi, kv.second);
    }

    cout << maxi << endl;
    return 0;
}
