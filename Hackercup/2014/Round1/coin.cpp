#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>


using namespace std;

int main()
{
	//freopen("2.txt","r",stdin);
	//freopen("2.out","w",stdout);
	int T,N,C,K;
	cin >> T;
	for(int cs=1;cs<=T;cs++)
	{
		cin >> N >> K >> C;
		int c1 = (K/N)*N;
		int best;
		if(c1>=C)
		{
			best = C;
		} else {
			best = c1+ C + N - K%N;
			for(int a=1;a<N;a++)
			{
				int t = K/(N-a) * (N-a);
				if(t<C)
					t += C + N - K%(N-a);
				best = min(best,t+a);
			}
		}
		cout << "Case #" << cs << ": " << best << endl;
	}
	return 0;
}