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


struct Clue
{
	int x,y,val;
	Clue(int a=0,int b=0,int c=0)
	{
		y=a;
		x=b;
		val=c;
	}
};

int n;
int grid[21][21];
vector<Clue> clueList;

int numSquares(int i,int j)
{
	int tot = 0;
	for (int y=i-1;y<=i+1;y++)
	{
		for (int x=j-1;x<=j+1;x++)
		{
			if (x<0 || y<0 || x>=n || y>=n) continue;
			tot++;
		}
	}
	return tot;
}

int numDetermined(int i, int j)
{
	int tot = 0;
	for (int y=i-1;y<=i+1;y++)
	{
		for (int x=j-1;x<=j+1;x++)
		{
			if (x<0 || y<0 || x>=n || y>=n) continue;
			if (grid[y][x]!=0) tot++;
		}
	}
	return tot;
}

int numMines(int i,int j)
{
	int tot = 0;
	for (int y=i-1;y<=i+1;y++)
	{
		for (int x=j-1;x<=j+1;x++)
		{
			if (x<0 || y<0 || x>=n || y>=n) continue;
			if (grid[y][x]==1) tot++;
		}
	}
	return tot;
}



bool isAllBombs(Clue cl)
{
	//cout << cl.x << " " << cl.y << " " << endl;
	return (numSquares(cl.y,cl.x)-numDetermined(cl.y,cl.x)+numMines(cl.y,cl.x)==cl.val);
}

bool isAllNotBombs(Clue cl)
{
	return numMines(cl.y,cl.x)==cl.val;
}

void fillAllBombs(Clue cl)
{

	for (int y=cl.y-1;y<=cl.y+1;y++)
	{
		for (int x=cl.x-1;x<=cl.x+1;x++)
		{
			if (x<0 || y<0 || x>=n || y>=n) continue;
			if (grid[y][x]==0) grid[y][x] = 1;
		}
	}
}

void fillAllNotBombs(Clue cl)
{

	for (int y=cl.y-1;y<=cl.y+1;y++)
	{
		for (int x=cl.x-1;x<=cl.x+1;x++)
		{
			if (x<0 || y<0 || x>=n || y>=n) continue;
			if (grid[y][x]==0) grid[y][x] = -1;
		}
	}
}

int main()
{
	freopen("DATA31.txt","r",stdin);
	for(int qq=0;qq!=5;qq++)
	{
		memset(grid,0,sizeof(grid));
	n=100;
	for (int i=0;i<n;i++)
	{
		string s;
		getline(cin,s);
		n = s.size();
		for (int j=0;j<n;j++)
		{
			if (isdigit(s[j]))
			{
				Clue cl(i,j,(int)(s[j]-'0'));
				clueList.push_back(cl);
			}
		}
	}


	Clue tmp;
	tmp.y = 3;
	tmp.x = 1;
	tmp.val = 9;

//	cout << isAllBombs(tmp) << endl;

	while (!clueList.empty())
	{
//		cout << clueList.size() << endl;
		int i=0;

		while (i!=clueList.size())
		{

			if (isAllBombs(clueList[i]))
			{
				//cout << "Bomb" << endl;
				fillAllBombs(clueList[i]);
				clueList.erase(clueList.begin()+i);
				break;
			}
			if (isAllNotBombs(clueList[i]))
			{
				//cout << "No" << endl;
				fillAllNotBombs(clueList[i]);
				clueList.erase(clueList.begin()+i);
				break;
			}
			i++;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (grid[i][j]==-1)
			{
				cout << ".";
			}
			else cout << "M";
		}
		cout << endl;
	}
	cout << endl;
	}
}