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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  map<char, string> mcc;

  mcc['a'] = "@";
  mcc['b'] = "8";
  mcc['c'] = "(";
  mcc['d'] = "|)";
  mcc['e'] = "3";
  mcc['f'] = "#";
  mcc['g'] = "6";
  mcc['h'] = "[-]";
  mcc['i'] = "|";
  mcc['j'] = "_|";
  mcc['k'] = "|<";
  mcc['l'] = "1";
  mcc['m'] = "[]\\/[]";
  mcc['n'] = "[]\\[]";
  mcc['o'] = "0";
  mcc['p'] = "|D";
  mcc['q'] = "(,)";
  mcc['r'] = "|Z";
  mcc['s'] = "$";
  mcc['t'] = "']['";
  mcc['u'] = "|_|";
  mcc['v'] = "\\/";
  mcc['w'] = "\\/\\/";
  mcc['x'] = "}{";
  mcc['y'] = "`/";
  mcc['z'] = "2";

  string s;
  getline(cin, s);
  for(int i = 0; i < s.size(); i++)
  {
    if(mcc.count(tolower(s[i])))
    {
      cout << mcc[tolower(s[i])];
    }
    else
    {
      cout << s[i];
    }
  }
  cout << endl;

  return 0;
}
