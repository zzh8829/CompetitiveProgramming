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

int front[200001];
int back[200001];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,t;
  cin >> n >> t;

  int uf = 1;
  int fn = 0;
  int bn = 0;

  for(int i = 0; i < n; i++)
  {
    char c;
    cin >> c;
    if(c == '.')
    {
      uf = 0;
      continue;
    }
    if(uf)
    {
      front[fn++] = c-'0';
    }
    else
    {
      back[bn++] = c-'0';
    }
  }

  int p1 = false;

  int ei = bn;

  for(int i = 0; i < bn ; i++)
  {
    if(back[i] >= 5)
    {
      if(t == 0) break;
      t--;

      if(i == 0)
      {
        p1 = true;
        ei = -1;
        break;
      }

      back[i-1]++;
      ei = i;
      break;
    }

    if(back[i] == 4)
    {
      int b = i;
      while(back[i] == 4)
      {
        i++;
      }

      if(back[i] >= 5)
      {
        while(t && i!=0 && back[i] >= 5)
        {
          back[i-1]++;
          t--;
          i--;
        }

        if(i == 0)
        {
          if(t && back[i] >= 5)
          {
            p1 = true;
            ei = -1;
            break;
          }
        }

        ei = i + 1;
        break;
      }
      else
      {
        i--;
      }
    }
  }

  if(p1)
  {
    for(int i = fn-1 ;i >= 0; i--)
    {
      front[i]++;
      if(front[i] != 10 )
      {
        break;
      }
      front[i] = 0;
    }
  }

  if(p1 && front[0] == 0)
    cout << "1";

  for(int i = 0; i < fn ;i++)
    cout << front[i];

  if(ei > 0)
  {
    cout << ".";
    for(int i = 0; i < ei; i++)
    {
      cout << back[i];
    }
  }
  cout << endl;
  

  return 0;
}
