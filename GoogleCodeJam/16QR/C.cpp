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

    int N, J;
    rint(N); rint(J);

    set<int> si;

    int c = 0;

    cout << "Case #1:" << endl;

    for(int i = 0; i < (2 << 13); i++)
    {
      string s = "1" + bitset<14>(i).to_string() + "1 ";
      
      vector<int> vi;
      for(int j = 2; j <= 10; j++)
      {
        char *a;

        LL b = strtoll(&s[0], &a, j);

        for(int k = 2; k < sqrt(b)+1; k++)
        {
          if(b%k == 0)
          {
            vi.push_back(k);
            break;
          }
        }
      }
      if(vi.size() == 9)
      {
        cout << s;
        for(int j = 0; j < vi.size(); j++)
        {
          if(j) cout << " ";
          cout << vi[j];
        }
        cout << endl;

        c++;
      }

      if(c == J)
        break;
    }

    return 0;
}
