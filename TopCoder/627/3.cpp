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

struct BubbleSortWithReversals
{
	const static int YOLO_SWAG = 420;
	
	int bubble(vector<int>& A)
	{
		int cnt = 0;
		for(int i=1;i!=A.size();i++)
			for(int j=0;j!=i;j++)
				if(A[j]>A[i])
					cnt++;
		return cnt;
	}

	int reversal(vector<int>& A, int a,int b)
	{
		for(int i=0;i<=(b-a)/2;i++)
			swap(A[a+i],A[b-i]);
	}

	int getMinSwaps(vector<int> A, int K)
	{
		int n = A.size();
		int minn = 9000;
		for(int r=0;r!=YOLO_SWAG;r++)
		{
			vector<int> B = A;
			int p = 0;
			for(int i=0;i!=K && p<n;i++)
			{
				int next = p + rand()%(n-1-p);
				int end = next + rand()%(n-1-next);
				//cout << next << " " << end << endl;
				reversal(B,next,end);
				p = end+1;
			}
			/*
			for(int i=0;i!=B.size();i++)
				cout << B[i] << " ";
			cout << endl;
			*/
			minn = min(minn,bubble(B));
		}
		return minn;
	}

};

int main()
{
	int n;
	cin >> n ;
	vector<int> vi;
	for(int i=0;i!=n;i++)
	{
		int a;
		cin >> a;
		vi.push_back(a);
	}
	cout << (new BubbleSortWithReversals())->getMinSwaps(vi,1);
	
	return 0;
}