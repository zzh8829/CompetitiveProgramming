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
#include <sstream>

using namespace std;

#define rint(x) scanf("%d", &(x))
#define endl '\n'

typedef long long LL;
typedef pair<int,int> I2;

string compress(string str) {
    stringstream ss;
    int i=0;
    while(i < str.size())
    {
        int j=1;
        ss << str[i];
        while(i+j < str.size() && str[i+j] == str[i]) j++;
        if(j>1)
        {
           ss << j;
        }
        i+=j;
    }
    return ss.str();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << compress("asdff") << endl;

    return 0;
}
