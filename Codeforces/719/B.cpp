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

  int n;
  string ss;
  
  cin >> n;

  ss.resize(n);

  for(int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    ss[i] = c;
  }

  int lastr = -1;
  int lastb = -1;

  int rc = 0;
  int bc = 0;
  for(int i = 0; i < n; i++)
  {
    if(ss[i] == 'r') 
    {
      rc++;
      lastr = i;
    }
    else
    {
      bc++;
      lastb = i;
    }
  }
  int mint = 0;
  // rb
  string s = ss;
  int t = 0;
  int lr = lastr;
  int lb = lastb;
  for(int i = 0; i < n; i++)
  {
    if(i%2 == 0)
    {
      if(s[i] == 'b')
      {
        if(lr > i)
        {
          while(lr > i && s[lr] != 'r' || lr%2 == 0) lr--;
        }

        if(lr > i)
        {
          swap(s[i], s[lr]);
          t++;
        }
        else
        {
          s[i] = 'r';
          t++;
        }
      }
    }
    else
    {
      if(s[i] == 'r')
      {
        if(lb > i)
        {
          while(lb > i && s[lb] != 'b' || lb%2 == 1) lb--;
        }

        if(lb > i)
        {
          swap(s[i], s[lb]);
          t++;
        }
        else
        {
          s[i] == 'b';
          t++;
        }
      }
    }
  }

  mint = t;

  t = 0;
  s = ss;
  lr = lastr;
  lb = lastb;
  // br
  for(int i = 0; i < n; i++)
  {
    if(i%2 == 1)
    {
      if(s[i] == 'b')
      {
        if(lr > i)
        {
          while(lr > i && s[lr] != 'r' || lr%2 == 1) lr--;
        }

        if(lr > i)
        {
          swap(s[i], s[lr]);
          t++;
        }
        else
        {
          s[i] = 'r';
          t++;
        }
      }
    }
    else
    {
      if(s[i] == 'r')
      {
        if(lb > i)
        {
          while(lb > i && s[lb] != 'b' || lb%2 == 0) lb--;
        }

        if(lb > i)
        {
          swap(s[i], s[lb]);
          t++;

        }
        else
        {
          s[i] = 'b';
          t++;
        }
      }
    }
  }

  mint = min(mint, t);

  cout << mint << endl;

  return 0;
}
