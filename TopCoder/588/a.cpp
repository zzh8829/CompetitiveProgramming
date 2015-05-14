#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <bitset>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

class KeyDungeonDiv2
{
public:
	int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys)
	{
		int rk = keys[0];
		int gk = keys[1];
		int wk = keys[2];

		int cnt = 0;
		for(int i=0;i!=doorR.size();i++)
		{
			int rl = doorR[i]-rk;
			int gl = doorG[i]-gk;

			int c = 0;
			if(rl>0) c +=rl;
			if(gl>0) c +=gl;
			if(c<=wk) cnt++;
		}
		return cnt;
	}
};

typedef vector<int> vi;
int main()
{
	


	int ra[] = {41,44,41,57,58,74,84,100,58,2,43,32,82,97,44,13,35,98,96,81,43,77,18,51,27,
 27,39,39,45,82,59,20,28,93,6,39,64,78,28,85,17,56,3,68,4,0,36,80,41,77};
	int ga[] = {67,15,53,36,88,29,26,57,68,99,97,27,51,70,3,49,65,75,35,92,66,0,23,96,38,86,
 98,31,26,75,30,2,92,78,100,99,38,26,85,74,77,15,16,48,100,88,55,93,99,54};
	int ka[] = {39,31,34};

	vi r(ra,ra+sizeof(ra)/sizeof(int));
	vi g(ga,ga+sizeof(ga)/sizeof(int));
	vi k(ka,ka+sizeof(ka)/sizeof(int));

	KeyDungeonDiv2 kd;
	cout << kd.countDoors(r,g,k) << endl;

	system("pause");
	return 0;
}