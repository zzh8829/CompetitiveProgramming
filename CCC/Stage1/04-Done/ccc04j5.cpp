#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

int DU=0,DD=1,DL=2,DR=3,level,width,xval;
struct P{
	P(int _x=0,int _y=0):x(_x),y(_y){};
	int x,y;
};
struct L{
	L(P _b,P _e,int _d=DU):b(_b),e(_e),d(_d){};
	P b,e;
	int d;
};
vector<L> ol,al,*ls = &ol, *nl = &al;;
void fra(int lev)
{
	if(lev%2) { ls = &al; nl = &ol; nl->clear();} 
	else { ls = &ol; nl = &al; nl->clear();	}
	if(lev == level) return;
	for(int i=0;i!=ls->size();i++)
	{
		L *cl = &(ls->at(i));
		if(cl->d==DU || cl->d == DD) {
			int dif = (cl->e.x - cl->b.x)/3;
			int lx = cl->b.x+dif;
			int rx = lx + dif;
			int by = cl->b.y;
			int sg = cl->d==DU?1:-1;
			nl->push_back(L(P(cl->b.x,by),P(lx,by),cl->d));
			nl->push_back(L(P(rx,by),P(cl->e.x,by),cl->d));
			nl->push_back(L(P(lx,by+sg*dif),P(rx,by+sg*dif),cl->d));
			if(cl->d == DU) {
				nl->push_back(L(P(lx,by),P(lx,by+sg*dif),DL));
				nl->push_back(L(P(rx,by),P(rx,by+sg*dif),DR));	
			} else {
				nl->push_back(L(P(lx,by+sg*dif),P(lx,by),DL));
				nl->push_back(L(P(rx,by+sg*dif),P(rx,by),DR));	
			}
		} else {
			int dif = (cl->e.y - cl->b.y)/3;
			int ly = cl->b.y+dif;
			int ry = ly + dif;
			int bx = cl->b.x;
			int sg = cl->d==DR?1:-1;
			nl->push_back(L(P(bx,cl->b.y),P(bx,ly),cl->d));
			nl->push_back(L(P(bx,ry),P(bx,cl->e.y),cl->d));
			nl->push_back(L(P(bx+sg*dif,ly),P(bx+sg*dif,ry),cl->d));
			if( cl->d == DR) {
				nl->push_back(L(P(bx,ly),P(bx+sg*dif,ly),DD));
				nl->push_back(L(P(bx,ry),P(bx+sg*dif,ry),DU));	
			} else {
				nl->push_back(L(P(bx+sg*dif,ly),P(bx,ly),DD));
				nl->push_back(L(P(bx+sg*dif,ry),P(bx,ry),DU));	
			}
		}
	}
	return fra(lev+1);
}

int main()
{
	cin >> level >> width >> xval;
	ls->push_back(L(P(0,1),P(width,1),DU));
	fra(0);
	set<int> si;
	for(int i=0;i!=ls->size();i++) {
		if(ls->at(i).d== DU || ls->at(i).d == DD) {
			if(ls->at(i).b.x <= xval && ls->at(i).e.x >= xval ) 
				si.insert(ls->at(i).b.y);
		} else if(ls->at(i).b.x == xval)
			for(int j=ls->at(i).b.y;j<=ls->at(i).e.y;j++)
				si.insert(j);
	}
	for(set<int>::iterator it = si.begin();it!=si.end();it++)
		cout << *it << " ";
	cout << endl;
	return 0;
}