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

    int n = 0;
    cin >> n;

    for(int t=  0; t < n ;t++) {
      int k,a;
      cin >> k;
      vector<int> vs;
      for(int i = 0; i < k; i++) {
        cin >> a;
        vs.push_back(a);
      }

      stack<int> s;

      int root = 0;
      int flag = true;
      for (int i=0; i<k; i++) {
        if (vs[i] < root) {
          flag = false;
          break;
        }
        while (!s.empty() && s.top()<=vs[i]) {
          root = s.top(); s.pop();
        }
        s.push(vs[i]);
      }
      if(flag) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }

    }
    return 0;
}
