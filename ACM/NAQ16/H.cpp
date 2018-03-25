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

int h[1000];
int b[1000];

int hh[100005];
int bb[100005];

int ht[100005];
int bt[100005];
int hbt[100005];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int H,B;
  cin >> H;

  for(int i = 0; i < H; i++)
    cin >> h[i];

  cin >> B;

  for(int i = 0; i < B; i++)
    cin >> b[i];

  sort(h, h+H, greater<int>());
  sort(b, b+B, greater<int>());

  for(int i = 0; i < 100002; i++)
  {
    ht[i] = bt[i] = 0x3f3f3f3f;
    hbt[i] = 0x3f3f3f3f;
  }

  hh[0] = 1;
  bb[0] = 1;

  ht[0] = 0;
  bt[0] = 0;
  for(int i = 0; i < H; i++)
  {
    for(int j = 100002; j >= h[i]; j--)
    {
      if(hh[j - h[i]])
      {
        hh[j] = 1;
        ht[j] = min(ht[j], ht[j - h[i]] + 1);
      }
    }
  }

  for(int i = 0; i < B; i++)
  {
    for(int j = 100002; j >= b[i]; j--)
    {
      if(bb[j - b[i]])
      {
        bb[j] = 1;
        bt[j] = min(bt[j], bt[j - b[i]] + 1);
      }
    }
  }

  int minbht = 0x3f3f3f3f;
  for(int j = 1; j <= 100002; j++)
  {
    if(hh[j] && bb[j])
    {
      minbht = min(minbht, ht[j] + bt[j]); 
    }
  }

  if(minbht == 0x3f3f3f3f)
  {
    cout << "impossible" << endl;
  }
  else
  {
    cout << minbht << endl;
  }
  
  return 0;
}
