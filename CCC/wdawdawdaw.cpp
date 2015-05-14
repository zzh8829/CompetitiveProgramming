#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,P;
vector<pair<int,int> > planets;

int main()
{
	cin >> N >> P;
	int fuel;
	for (int i=0;i<N;i++)
	{
		int val,cost;
		cin >> val >> cost;
		if (P-1==i) fuel = val;
		else if (val>=cost) planets.push_back(make_pair(cost,val));
	}
	sort(planets.begin(),planets.end());
	int cnt = 1;
	for (int i=0;i<planets.size();i++)
	{
		if (planets[i].first>fuel) break;
		else
		{
			cnt++;
			fuel += planets[i].second-planets[i].first;
		}
	}
	cout << fuel << endl << cnt << endl;
}