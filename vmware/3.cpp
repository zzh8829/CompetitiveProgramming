#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
 * Complete the function below.
 */
int maxLength(vector <int> a, int k) {

  vector<int> ps;
  ps.push_back(0);
  for(int i: a) {
    ps.push_back(ps[ps.size()-1] + i);
  }

  int s = 0;
  int maxl = 0;

  for(int i = 0; i < a.size(); i++) {
    auto it = upper_bound(ps.begin(), ps.end(), k - ps[i]);
    maxl = max(maxl, (int)(it - ps.begin()) - i);
  }
  return maxl;
}
