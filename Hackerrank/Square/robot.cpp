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

map<I2,int> mii;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,X,Y,M;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> X >> Y;
        mii.insert(make_pair(I2(X,Y),i));
    }
    cin >> M;
    char c;
    int x = 0, y = 0, d = 0;
    for(int i = 0; i < M; i++)
    {
        cin >> c;
        switch(c)
        {
            case 'L':
                d = (d+3)%4;
                break;
            case 'R':
                d = (d+1)%4;
                break;
            case 'F':
                int tx = x;
                int ty = y;
                while(mii.count(I2(tx + dx[d],ty + dy[d])))
                {
                    tx += dx[d];
                    ty += dy[d];
                }
                while(!(tx == x && ty == y))
                {
                    int id = mii[I2(tx,ty)];
                    mii.erase(mii.find(I2(tx,ty)));
                    mii.insert(make_pair(I2(tx+dx[d],ty+dy[d]),id));
                    tx -= dx[d];
                    ty -= dy[d];
                }
                x += dx[d];
                y += dy[d];
                break;
        }
    }
    vector<pair<int,I2>> vii;
    for(auto &e: mii)
    {
        vii.push_back(make_pair(e.second,e.first));
    }
    sort(vii.begin(),vii.end());
    for(auto &e: vii)
    {
        cout << e.second.first << " " << e.second.second << endl;
    }
    return 0;
}
