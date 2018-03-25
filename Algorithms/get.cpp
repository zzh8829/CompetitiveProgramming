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

int v[100000005];

struct P
{
    int a,b;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<int,int> p0(1,2);
    for(int i=0;i!=100000000;i++)
        v[i] = get<0>(p0) + get<1>(p0);

    clock_t s = clock();
    pair<int,int> p(1,2);
    for(int i=0;i!=100000000;i++)
        v[i] = p.first + p.second;

    cout << (clock() - s)/(double)CLOCKS_PER_SEC << endl;
    s = clock();

    pair<int,int> p2(3,4);
    for(int i=0;i!=100000000;i++)
        v[i] = get<0>(p2) + get<1>(p2);

    cout << (clock() - s)/(double)CLOCKS_PER_SEC << endl;
    s = clock();

    P p3;
    p3.a = 5;
    p3.b = 6;
    for(int i=0;i!=100000000;i++)
        v[i] = p3.a + p3.b;

    cout << (clock() - s)/(double)CLOCKS_PER_SEC << endl;
    s = clock();


    return 0;
}
