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

int minn[5005][5005];
int maxn[5005][5005];
int sum[5005];

string s;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> s;

  if(s.size()%2==1)
  {
    cout << "impossible" << endl;
    return 0;
  }
  int t = 0;
  for(int i=0; i < s.size(); i++)
  {
    if(s[i] == '(')
      t++;
    else
      t--;

    sum[i+1] = t;
  }

  for(int i= 1;i <= s.size(); i++)
  {
    for(int j= i;j <= s.size(); j++)
    {
      maxn[i][j] = max(maxn[i][j-1], sum[j]);
      minn[i][j] = min(minn[i][j-1], sum[j]);
    }
  }

  if(sum[s.size()] == 0 && maxn[1][s.size()] * minn[1][s.size()] == 0)
  {
    cout << "possible" << endl;
    return 0;
  }

  for(int i = 1; i <= s.size(); i++)
  {
    for(int j = i; j <= s.size(); j++)
    {

      int tmax = max(maxn[1][i], maxn[j+1][s.size()]);
      tmax = max(tmax, -minn[i][j]);
      
      int tmin = min(minn[1][i], minn[j+1][s.size()]);
      tmin = min(tmin, -maxn[i][j]);

      int tsum = sum[i-1] - (sum[j] - sum[i-1]) + sum[s.size()] - sum[j];

      if(i == 4 && j == 6)
      {
        cout << maxn[1][i] << maxn[i+1][j] << maxn[j+1][s.size()] << endl;
        cout << minn[1][i] << minn[i+1][j] << minn[j+1][s.size()] << endl;
        cout << tmax << tmin << tsum << endl;
      }

      if(tsum == 0 && tmax * tmin == 0)
      {
        cout << "possible" << endl;
        return 0;
      }
    }
  }

  cout << "impossible" << endl;

  return 0;
}
