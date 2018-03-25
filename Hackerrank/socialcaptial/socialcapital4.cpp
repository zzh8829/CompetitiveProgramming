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
typedef pair<LL,LL> L2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,K,L,M;
    cin >> N;

    vector<L2> stack;
    for(int i = 0 ;i <= 500000; i++)
        stack.push_back(L2(0,0));

    int sp = 1;

    for(int i= 0; i < N; i++)
    {
        string c;
        LL d;
        int x;
        cin >> c;
        switch(c[2])
        {
        case 'u': // push 
            cin >> stack[sp].first;
            cout << stack[sp].first << endl;
            sp++;
            break;
        case 'o': // pop
            d = stack[sp].second;
            stack[sp].first = 0;
            stack[sp].second = 0;
            sp--;
            if(sp > 0)
            {
                stack[sp].second += d;
                cout << stack[sp].first + stack[sp].second << endl;
            } 
            else
            {
                sp++;
                cout << "EMPTY";
            }
            break;
        case 'n': // inc
            cin >> x >> d;
            stack[x].second += d;
            cout << stack[sp].first + stack[sp].second << endl;
            break;
        }
    }
    
    return 0;
}
