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

/*
 * Complete the function below.
 */

/* Write your custom functions here */
void mergeArrays(int a[], int b[], int M) {
    int* c = new int[M*2];
    int p1=0,p2=0,p3=0;
    while(p1<M && p2<M)
    {
        if(a[p1] < b[p2])
        {
            c[p3++] = a[p1++];
        } else {
            c[p3++] = b[p2++];
        }
    }
    if(p1==M)
    {
        while(p2<M)
            c[p3++] = b[p2++];
    }
    else
    {
        while(p1<M)
            c[p3++] = a[p1++];
    }
    for(int i=0;i<2*M;i++)
        b[i] = c[i];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    return 0;
}
