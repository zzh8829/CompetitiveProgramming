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

  int moon[100] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 ,14 ,15, 14,
              13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

  vector<int> m;
  for(int i = 0;i < 300; i++)
  {
    m.push_back(moon[i%30]);
  }

  int N;
  vector<int> m2;
  cin >> N;
  for(int i = 0; i < N; i++)
  {
    int x;
    cin >> x;
    m2.push_back(x);
  }

  for(int j = 0; j < 200; j++)
  {
    int s = true;
    for(int i = 0; i < N ; i++)
    {
      if(m2[i] != m[j + i])
      {
        
        s = false;
        break;
      }
    }

    if(s)
    {
      if(N == 1 && m[j + N - 1] != 15 && m[j + N - 1] != 0)
      {
        cout << "-1" << endl;
      }
      else
      {
        cout << ((m[j + N] > m[j + N - 1])?"UP":"DOWN") << endl;
      }
      return 0;
    }
  }

  cout << "-1" << endl;

  return 0;
}
