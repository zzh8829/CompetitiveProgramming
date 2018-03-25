#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <numeric>
#include <memory.h>
#include <cstdio>
#include <assert.h>

using namespace std;

#define pb push_back
#define INF 1011111111
#define FOR(i, a, b) for (int _n(b), i(a); i < _n; i++)
#define rep(i, n) FOR(i, 0, n)
#define CL(a, v) memset((a), (v), sizeof(a))
#define mp make_pair
#define X first
#define Y second
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> pii;

/*** TEMPLATE CODE ENDS HERE */

const int maxn = 1e5 + 5;
VI g[maxn];
map<string, int> id;
vector<string> name;

void go(int at, stringstream &ss) {
  int to = -1;
  for (string token; ss >> token;) {
    if (token == ")") {
      break;
    } else if (token == "(") {
      go(to, ss);
    } else {
      to = (int)id.size();
      int nid = (int)id.size();
      id[token] = nid;
      name.push_back(token);
      if (at >= 0) {
        g[at].pb(to);
        g[to].pb(at);
      }
    }
  }
}

// build tin, tout
VI tin, tout;
void dfs(int at, int from) {
  static int tm = -1;
  tin[at] = ++tm;
  rep(i, (int)g[at].size()) {
    int to = g[at][i];
    if (to != from) {
      dfs(to, at);
    }
  }
  tout[at] = tm;
}

void print(int at, int from) {
  cout << name[at] << " " << tin[at] << " " << tout[at] << endl;
  rep(i, (int)g[at].size()) {
    int to = g[at][i];
    if (to != from) {
      print(to, at);
    }
  }
}

// Persistent tree

struct Node {
  int val;
  int left, right;
  Node(int val, int l, int r) : val(val), left(l), right(r) {}
};

vector<Node> nodes;

int GetNewNode(int val, int left, int right) {
  Node node(val, left, right);
  nodes.push_back(node);
  return (int)nodes.size() - 1;
}

int GetVal(int pos) {
  if (pos == -1) {
    return 0;
  }
  return nodes[pos].val;
}

int build(int l, int r) {
  if (l == r) {
    return GetNewNode(0, -1, -1);
  }
  int m = (l + r) / 2;
  int left = build(l, m);
  int right = build(m + 1, r);
  int val = GetVal(left) + GetVal(right);

  return GetNewNode(val, left, right);
}

int modify(int at, int l, int r, int idx, int val) {
  assert(at != -1);
  if (l == r) {
    assert(idx == l);
    return GetNewNode(nodes[at].val + val, -1, -1);
  }
  int m = (l + r) / 2;
  int left = -2, right = -2;
  if (idx <= m) {
    left = modify(nodes[at].left, l, m, idx, val);
    right = nodes[at].right;
  } else {
    left = nodes[at].left;
    right = modify(nodes[at].right, m + 1, r, idx, val);
  }
  int s = GetVal(left) + GetVal(right);
  return GetNewNode(s, left, right);
}

int sum(int at, int l, int r, int ql, int qr) {
  if (ql > qr || at == -1) {
    return 0;
  }
  if (l == ql && r == qr) {
    return GetVal(at);
  }
  int m = (l + r) / 2;
  int s1 = sum(nodes[at].left, l, m, ql, min(qr, m));
  int s2 = sum(nodes[at].right, m + 1, r, max(m + 1, ql), qr);
  return s1 + s2;
}

void PrintTree(int at) {
  if (at == -1) {
    return;
  }
  cout << "at: " << at << " val: " << nodes[at].val
       << " left: " << nodes[at].left << " right: " << nodes[at].right << endl;
  PrintTree(nodes[at].left);
  PrintTree(nodes[at].right);
}

int main() {
#ifdef LOCAL_HOST
  freopen("input.txt", "r", stdin);
// freopen("output.txt","w",stdout);
#endif

  ios_base::sync_with_stdio(false);

  int N, M, K;

  cin >> N;
  {
    string tree;
    std::getline(std::cin, tree);
    std::getline(std::cin, tree);
    stringstream ss;
    ss << tree;
    ss << " )";
    go(-1, ss);
  }

  // Build Euler tour
  tin.resize(id.size());
  tout.resize(id.size());
  dfs(0, -1);
  // debug
  // print(0, -1);
  // Parse queries
  cin >> M;
  vector<pair<string, int> > msgs;
  {
    string line;
    std::getline(std::cin, line);
    rep(i, M) {
      std::getline(std::cin, line);
      string category = line.substr(0, line.find_first_of(':'));
      string body = line.substr(line.find_first_of(':') + 2);
      msgs.push_back(mp(body, id[category]));
    }
    SORT(msgs);
  }

  int R = N - 1;
  // put msgs to persistent tree
  VI roots(msgs.size() + 1, -1);
  roots[0] = build(0, R);
  rep(i, (int)msgs.size()) {
    roots[i + 1] = modify(roots[i], 0, R, msgs[i].Y, 1);
  }

  cin >> K;
  {
    string line;
    std::getline(std::cin, line);
    rep(i, K) {
      std::getline(std::cin, line);

      string category = line.substr(0, line.find_first_of(' '));
      int cid = id[category];
      string body = line.substr(line.find_first_of(' ') + 1);
      int idx = int(lower_bound(all(msgs), mp(body, -1)) - msgs.begin());
      int idx2 =
          int(lower_bound(all(msgs), mp(body + char(200), -1)) - msgs.begin());
      if (idx2 < idx) {
        cout << 0 << endl;
        continue;
      }

      int cnt1 = sum(roots[idx2], 0, R, tin[cid], tout[cid]);
      int cnt2 = sum(roots[idx], 0, R, tin[cid], tout[cid]);

      cout << cnt1 - cnt2 << endl;
    }
  }

#ifdef LOCAL_HOST
  printf("TIME: %.3lf\n", double(clock()) / CLOCKS_PER_SEC);
#endif

  return 0;
}