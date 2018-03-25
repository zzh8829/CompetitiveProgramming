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

      int c = 0;
      int k = 0;
      LL x = N;
      int v[200] = {0};

      if(N == 0)
      {
        cout << "Case #" << t + 1 << ": INSOMNIA" << endl;
      } 
      else 
      {
        while(k < 10000000)
        {
          string s = to_string(x);
          for(int i = 0; i < s.size(); i++)
          {
            if(!v[s[i]])
            {
              c++;
              v[s[i]] = 1;
            }
          }
          if(c == 10)
          {
            cout << "Case #" << t + 1 << ": " << x << endl;
            break;
          }
          x += N;
          k ++;
        }
      }
    }

    return 0;
}
