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

bool gen[2][2][2][2][2]
		[2][2][2][2][2]
		[2][2][2][2][2]
		[2][2][2][2][2];

int tim[2][2][2][2][2]
		[2][2][2][2][2]
		[2][2][2][2][2]
		[2][2][2][2][2];

int R,C,L,O,B,A;

int index(int r,int c){

}

int dr[] = {1,-1,0,0,1,1,-1,-1};
int dc[] = {0,0,1,-1,1,-1,1,-1};

bool st[20],stb1[20],stb2[20];
bool *st2=stb1,*st3=stb2;
bool in[20];

bool* getg(bool* s)
{
	return &gen[s[0]][s[1]][s[2]][s[3]][s[4]]
		[s[5]][s[6]][s[7]][s[8]][s[9]]
		[s[10]][s[11]][s[12]][s[13]][s[14]]
		[s[15]][s[16]][s[17]][s[18]][s[19]];
}

int* gett(bool* s)
{
	return &tim[s[0]][s[1]][s[2]][s[3]][s[4]]
		[s[5]][s[6]][s[7]][s[8]][s[9]]
		[s[10]][s[11]][s[12]][s[13]][s[14]]
		[s[15]][s[16]][s[17]][s[18]][s[19]];
}

bool setg(bool* s)
{
	if(*getg(s))
		return false;
	*getg(s) = true;
    return true;
}

void next(bool* ost,bool* nst)
{
	memcpy(nst,ost,sizeof(st));
	for(int i=0;i!=R;i++)
	{
		for(int j=0;j!=C;j++)
		{
			int nn = 0;
			int idx;
			for(int d=0;d!=8;d++)
			{
				int tr = i+dr[d];
				int tc = j+dc[d];
				if(tr<0||tc<0||tr>=R||tc>=C)continue;
				if(ost[tr*C+tc])nn++;
			}
			idx = i*C+j;
			if(ost[idx]) {
				if(nn < L || nn > O)
					nst[idx] = 0;
			} else {
				if(nn > B)
					nst[idx] = 1;
			}
		}
	}
}

void recall(int r,int c,int n)
{
	if(n==A)
	{
		if(*getg(st))return;
		memcpy(st2,st,sizeof(st));
		do{
			next(st2,st3);
			swap(st2,st3);
		}while(setg(st2));
		return;
	}
	int nr = r;
	int nc = c+1;
	if(nc==C)
	{
		nr++;
		nc=0;
	}
	int idx = r*C+c;
	recall(nr,nc,n+1);
	st[idx]=1;
	recall(nr,nc,n+1);
	st[idx]=0;
}

void recfind(int r,int c,int n)
{
	if(n==A)
	{
		if(*getg(st))return;
		memcpy(st2,st,sizeof(st));
		int ng = 0;
		while(true)
		{
			ng++;
			next(st2,st3);
			int* og = gett(st3);
			if(*og == 0)*og=ng;
			else if(*og > ng)*og=ng;
			else break;
			swap(st2,st3);
		}
		return;
	}
	int nr = r;
	int nc = c+1;
	if(nc==C)
	{
		nr++;
		nc=0;
	}
	int idx = r*C+c;
	recfind(nr,nc,n+1);
	st[idx]=1;
	recfind(nr,nc,n+1);
	st[idx]=0;
}

int main()
{
	cin >> R >> C >> L >> O >> B;
	A = R*C;
	recall(0,0,0);
	string s;
	for(int i=0;i!=R;i++)
	{
		cin >> s;
		for(int j=0;j!=C;j++)
			in[i*C+j] = s[j]=='*'?1:0;
	}
	if(!(*getg(in)))
	{
		cout << 0 << endl;
		return 0 ;
	}
	recfind(0,0,0);
	int t = *gett(in);
	cout << (t==0?-1:t) << endl;
	return 0;
}