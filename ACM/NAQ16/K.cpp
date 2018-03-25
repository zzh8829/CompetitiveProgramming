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

#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int t = 0; t < n; t++)
  {
    int l1,a1,l2,a2,lt,at;
    cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

    int sol = 0;
    int sx;
    int sy;
    for(int x = 1; x <= 10000; x++)
    {
      int y = (lt - x * l1) / l2;
      int y2 = (at - x * a1) / a2;

      if(y <= 0 || y2 <= 0 || y != y2 || (y * l2) != (lt - x * l1) || (y2 * a2) != (at - x * a1))
      {
        continue;
      }

      // cout << x << " " << y << endl;

      // cout << y * l2 << " " << (lt - x * l1) << endl;
      // cout << y2 * a2 << " " << (at - x * a1) << endl;

      sol ++ ;
      sx = x;
      sy = y;
    }

    if(sol == 1)
    {
      cout << sx << " " << sy << endl;
    }
    else 
    {
      cout << "?" << endl;
    }
  }

  return 0;
}
