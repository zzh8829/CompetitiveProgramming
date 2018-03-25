/*
 * Complete the function below.
 */

#include <bitset>
#include <algorithm>

vector<string> buildSubsequences(string s) {
  vector<string> vs;
  for(int i = 1; i < (1<<s.size()); i++) {
    bitset<20> bs(i);
    string ss = "";
    for(int j = 0; j < s.size(); j++) {
      if(bs[j]) {
        ss += s[j];
      }
    }
    vs.push_back(ss);
  }
  sort(vs.begin(), vs.end());
  return vs;
}


def powerset(s):
    n = len(s)
    masks = [1<<j for j in xrange(n)]
    for i in xrange(2**n):
        yield [s[j] for j in range(n) if (masks[j] & i)]

  int n = s.size();
  vector<int> masks;
  for(int i = 0; i < n; i++)
    masks.push_back(1<<i);
  for(int i = 0; i < (1<<n); i++ ) {
    string ss = "";
    for(int j =0; j < n; j++) {
      if(masks[j] & i) {
        ss += s[j];
      }
    }
    vs.push_back(ss);
  }
