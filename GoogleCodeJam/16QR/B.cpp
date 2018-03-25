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
      string s;
      cin >> s;

      int c = 0;
      
      for(int i = s.size() - 1; i >= 0; i--)
      {
        if(s[i] == '-')
        {
          for(int j = 0; j <= i; j++)
          {
            if(s[j] == '-')
              s[j] = '+';
            else
              s[j] = '-';
          }
          c++;
        }
      }

      cout << "Case #" << t + 1 << ": " << c << endl;
    }

    return 0;
}
