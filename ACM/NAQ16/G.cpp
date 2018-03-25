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
#include <sstream>

using namespace std;

#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int l = s.size();

  if(l <= 9)
  {
    int k;
    istringstream ss(s);
    ss >> k; 
    int i = 1;
    for(int j = 1; j <= 12; j++)
    {
      i = i * j;
      if(k == i)
      {
        cout << j << endl;
        return 0;
      }
    }
  }

  double dig = 0;
  int i = 1;

  while(true)
  {
    dig += log10(i);

    // if(dig > l - 100)
    // {
    //   cout << dig << " " << l << endl;
    // }

    double dig2 = dig;
    if(ceil(dig2) == l)
    {
      cout << i << endl;
      return 0;
    }

    if(ceil(dig2) > l)
      break;

    i++;
  }

  return 0;
}
