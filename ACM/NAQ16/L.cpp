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
typedef pair<double, double> D2;
typedef pair<D2, D2> L;

double px[10];
double py[10];

D2 pol[10];

int intersect(L l1, L l2)
{
  float x1 = l1.first.first, x2 = l1.second.first, x3 = l2.first.first, x4 = l2.second.first;
  float y1 = l1.first.second, y2 = l1.second.second, y3 = l2.first.second, y4 = l2.second.second;
   
  float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

  if (d == 0) return false;
   
  float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
  float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
  float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;

  if ( x <= min(x1, x2) || x >= max(x1, x2) ||
    x <= min(x3, x4) || x >= max(x3, x4) ) return false;
  if ( y <= min(y1, y2) || y >= max(y1, y2) ||
    y <= min(y3, y4) || y >= max(y3, y4) ) return false;

  return true;
}

int intersect2(L l1, L l2)
{
  double p0_x = l1.first.first, p1_x = l1.second.first, p2_x = l2.first.first, p3_x = l2.second.first;
  double p0_y = l1.first.second, p1_y = l1.second.second, p2_y = l2.first.second, p3_y = l2.second.second;

  double s1_x, s1_y, s2_x, s2_y;
  s1_x = p1_x - p0_x;     s1_y = p1_y - p0_y;
  s2_x = p3_x - p2_x;     s2_y = p3_y - p2_y;

  double s, t;
  s = (-s1_y * (p0_x - p2_x) + s1_x * (p0_y - p2_y)) / (-s2_x * s1_y + s1_x * s2_y);
  t = ( s2_x * (p0_y - p2_y) - s2_y * (p0_x - p2_x)) / (-s2_x * s1_y + s1_x * s2_y);

  if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
  {
    return true;
  }

  return false;
}

int simple()
{
  for(int i = 1; i < 8; i++)
  {
    for(int j = 1; j < 8; j++) if(abs(i-j) > 1 && abs(i-j) < 6)
    {
      if(intersect2(L(pol[i-1], pol[i]), L(pol[j-1], pol[j])))
      {
        return false;
      }
    }
  }
  return true;
}


double prob;

double area()
{
  double a = 0;
  for(int i = 0; i < 7; i++)
  {
    a += pol[i].first * pol[i+1].second;
  }
  for(int i = 0; i < 7; i++)
  {
    a -= pol[i+1].first * pol[i].second;
  }
  return abs(a)/2;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int c=0; c < n; c++)
  {
    cin >> px[0] >> py[0];
    cin >> px[1] >> py[1];
    cin >> px[2] >> py[2];
    cin >> px[3] >> py[3];
    cin >> px[4] >> py[4];
    cin >> px[5] >> py[5];
    cin >> px[6] >> py[6];

    cin >> prob;

    int arr[6] = {1,2,3,4,5,6};

    pol[0] = D2(px[0], py[0]);
    pol[7] = D2(px[0], py[0]);

    do {
      for(int p = 0; p < 6; p++)
      {
        int idx = arr[p];
        //cout << idx << " ";
        pol[p+1] = D2(px[idx], py[idx]);
      }
      //cout << endl;

      if(simple())
      {

        double pp = (area()/4);
        pp = pp * pp * pp;
        

        // if(arr[0] == 1 && arr[1] == 2)
        // {
        //   cout << "1";
        //   for(int p = 0; p < 6; p++)
        //   {
        //     cout << " " << arr[p] + 1;
        //   }
        //   cout << endl;

        //   for(int p = 0; p < 8; p++)
        //   {
        //     cout << pol[p].first << ", " << pol[p].second << "| ";
        //   }
        //   cout << endl;

        //   cout << pp - prob << endl;
        // }

        if(abs(pp - prob) <= 1e-5 )
        {
          cout << "1";
          for(int p = 0; p < 6; p++)
          {
            cout << " " << arr[p] + 1;
          }
          cout << endl;
          break;
        }
      }
    } while( next_permutation(arr, arr+6 ));
  }

  

  return 0;
}
