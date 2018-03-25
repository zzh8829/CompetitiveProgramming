#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
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
#include <vector>

using namespace std;

#define rint(x) scanf("%d", &(x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

int m[101][101];

deque<I2> qu;

int main()
{
    int R,C;
    rint(R); rint(C);
    int M;
    rint(M);
    for(int i = 0; i < M; i++)
    {
      int r,c;
      rint(r); rint(c);
      m[r][c] = 1;
    }

    int N;
    rint(N);

    int sr = 0;
    int sc = 0;
    qu.push_front(I2(0,0));
    for(int i = 0; i < N; i++)
    {
      char c;
      cin >> c;

      //cout << c << sr << sc << endl;

      int tr = sr;
      int tc = sc;
      if(c == 'U')
      {
        tr -= 1;
      }
      else if (c== 'R')
      {
        tc += 1;
      }
      else if (c == 'L')
      {
        tc -= 1;
      }
      else if (c == 'D')
      {
        tr += 1;
      }
      if(m[tr][tc] == 1)
      {
        m[tr][tc] = 0;
      }
      else
      {
        qu.pop_back();
      }

      for(int j = 0 ;j < qu.size(); j++)
      {
        if(tr == qu[j].first && tc == qu[j].second)
        {
        cout << i + 1 << endl;
        return 0;
        }
      }
      qu.push_front(I2(tr,tc));

      sr = tr;
      sc = tc;
    }
    cout << -1 << endl;
    return 0;
}
