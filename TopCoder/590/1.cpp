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


int dr[] = {-1,-1,0,1,1,1,0,-1};
int dc[] = {0,1,1,1,0,-1,-1,-1};

class FoxAndGomoku
{
public:
	string win(vector <string> board)
	{
		int row = board.size();
		int col = board[0].size();
		for(int r=0;r!=row;r++)
			for(int c=0;c!=col;c++)
			{
				for(int i=0;i!=8;i++)
				{
					int tr = r;
					int tc = c;
					int f = true;
					for(int j=0;j!=5;j++)
					{
						if(j)
						{
							tr+=dr[i];
							tc+=dc[i];
						}
						if(tc<0 || tr<0 || tr>=col || tc>= col || board[tr][tc]!='o')
						{
							f = false;
							break;
						}
					}
					if(f)
					return "found";
				}
			}
		return "not found";
	}
};
int main()
{
	
	
	return 0;
}