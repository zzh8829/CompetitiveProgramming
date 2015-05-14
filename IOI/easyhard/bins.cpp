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

int M,N;
int A[20001];
int B[1001];
int B2[1001];

int main()
{
	scanf("%d%d",&M,&N);
	for(int i=0;i!=N;i++)
	{
		scanf("%d",A+i);
		if(i<N/2)
			B[A[i]]++;
		else if(i<(N/2)*2)
			B2[A[i]]++;
	}
	for(int i=N/2;i>0;i--)
	{
		bool f=true;
		int ext=0;
		if(B[M]) ext = -9999999;
		for(int j=M;j>=1;j--)
		{
			ext += B2[j]-B[j-1];
			if(ext < 0) 
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			cout << i << endl;
			return 0;
		}
		B2[A[i*2-1]]--;
		B2[A[i*2-2]]--;
		B2[A[i-1]]++;
		B[A[i-1]]--;
	}
	cout << 0 << endl;
	return 0;
}