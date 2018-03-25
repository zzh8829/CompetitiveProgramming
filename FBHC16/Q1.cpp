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

    int T;
    rint(T);
    for(int t = 0; t < T; t++)
    {
      int N;
      rint(N);

      set<I2> si2;

      for(int i = 0; i < N; i++)
      {
        int a,b;
        rint(a);rint(b);
        si2.insert(I2(a,b));
      }

      vector<I2> vi2(si2.begin(), si2.end());
     
      int tot = 0;
      for(int i = 0; i < vi2.size(); i++)
      {
        map<int, int> mii;
        for(int j = 0; j < vi2.size(); j++) if(i != j)
        {
          int d = (vi2[i].first - vi2[j].first) * (vi2[i].first - vi2[j].first) + (vi2[i].second - vi2[j].second) * (vi2[i].second - vi2[j].second);
          if(!mii.count(d))
          {
            mii[d] = 0;
          }
          mii[d] ++;
        }
        
        for(auto& kv : mii)
        {
          tot += (kv.second * (kv.second - 1))/2;
        }
      }
      printf("Case #%d: %d\n", t+1, tot);
    }
    return 0;
}
