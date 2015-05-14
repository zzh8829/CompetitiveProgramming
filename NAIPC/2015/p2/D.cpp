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

int main()
{
	int a,b,c,d;
	int x,y,z,w;
	scanf("%d %d %d %d\n%d %d %d %d",&a,&b,&c,&d,&x,&y,&z,&w);
	if(a+b+c+d == x+y+z+w)
		printf("Tie\n");
	else if(a+b+c+d > x+y+z+w)
		printf("Gunnar\n");
	else
		printf("Emma\n");
	return 0;
}