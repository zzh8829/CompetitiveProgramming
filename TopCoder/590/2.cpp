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
#include <queue>

using namespace std;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

typedef pair<int,int> Pos;
typedef map<Pos, vector<int> > Mpvi;
Mpvi mpvi;
int np=1;
int v[20][20];
int nr,nc;


class FoxAndGo
{
public:


	int maxKill(vector <string> board)
	{
		int base = 0;
		nr = board.size();
		nc = board[0].size();
		memset(v,0,sizeof(v));
		
		// make white list
		for(int i=0;i!=nr;i++)
		{
			for(int j=0;j!=nc;j++)
			{
				if(!v[i][j] && board[i][j]=='o')
				{
					int size = 1;
					queue<Pos> q;
					Pos org = Pos(i,j);
					q.push(org);
					set<Pos> sp;
					v[i][j]=np;

					int opr,opc;

					while(!q.empty())
					{
						Pos p = q.front();q.pop();
						for(int i=0;i!=4;i++)
						{
							int tr = p.first  +dr[i];
							int tc = p.second +dc[i];
							if(tr<0 || tc<0 || tr>= nr || tc>=nc || v[tr][tc] )
								continue;
							if(board[tr][tc]=='.')
							{
								sp.insert(Pos(tr,tc));
								opr = tr;
								opc = tc;
							}
							else if(board[tr][tc]=='o')
							{
								v[tr][tc] = np;
								size++;
								q.push(Pos(tr,tc));
							}
						}
					}
					if(sp.size()==1)
					{
						Pos op(opr,opc);
						if(!mpvi.count(op))
						{
							mpvi[op] = vector<int>();
						}
						mpvi[op].push_back(size);
						np++;
					}
					if(sp.size()==0)
					{
						base += size;
					}
				}
			}
		}

		int maxn = base;
		for(Mpvi::iterator it = mpvi.begin();it!=mpvi.end();it++)
		{
			//cout << it->first.first << " " << it->first.second << endl;
			int sum = base;
			for(int i=0;i!=it->second.size();i++)
				sum += it->second.at(i);
			if(sum > maxn ) maxn = sum;
		}

		return maxn;
	}
};

int main()
{
	vector<string> b;
b.push_back(".......");
b.push_back(".......");
b.push_back(".......");
b.push_back("xxxx...");
b.push_back("ooox...");
b.push_back("ooox...");
b.push_back("ooox...");

	FoxAndGo f;
	cout << f.maxKill(b) << endl;

	cin.get();
	cin.get();

	
	return 0;
}