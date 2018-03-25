#include <iostream>
#include <vector>

using namespace std;

int n;
int w[2001];
int bt[2001];
int t;
vector<int> hear[2001];

int waittime[2001];

void doBark(int time,int dog)
{
	for(int i=0;i!=hear[dog].size();i++)
	{
		int hd = hear[dog][i];
		if(waittime[hd] < time)
		waittime[hd] = time+w[hd];
	}
	bt[dog]++;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> w[i];
	}
	int f,a,b;
	cin >> f;
	for(int i=0;i!=f;i++)
	{
		cin >> a >> b;
		hear[a].push_back(b);
	}
	cin >> t;
	for(int i=1;i<=n;i++) 
	{
		waittime[i] = -1;
	}
	waittime[1] = 0;
	for(int i=0;i<=t;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			if( waittime[j] == i)
			{
				doBark(i,j);
			}	
		}

	}
	for(int i=1;i<=n;i++)
	{
		cout << bt[i] << endl;
	}
	return 0;
}