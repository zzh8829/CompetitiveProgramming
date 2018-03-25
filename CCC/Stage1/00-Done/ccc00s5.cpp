#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

struct P
{
	P(float a = 0,float b=0):x(a),y(b){};
	float x,y;
	float ss;
}sp[1001];
bool out[1001];

float dis(const P& a,const P& b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i!=n;i++)
	{
		scanf("%f%f",&sp[i].x,&sp[i].y);
		sp[i].ss = sp[i].x*sp[i].x + sp[i].y*sp[i].y;
	}
	for(int i=0;i!=n;i++)if(!out[i])
	{
		float l =    0;
		float r = 1000;
		for(int j=0;j!=n;j++)if(!out[j] && i!=j)
		{
			if(sp[i].x == sp[j].x)
			{
				if(sp[i].y < sp[j].y)
				{
					out[j]=1;
					continue;
				}
				if(sp[j].y < sp[i].y)
				{
					out[i]=1;
					break;
				}
			}
			float interx = (sp[j].ss - sp[i].ss)/2/(sp[j].x-sp[i].x);
			if(sp[i].x < sp[j].x)
				r = min(interx,r);
			else
				l = max(interx,l);
			if(l-r>0.0001)
			{
				out[i]=1;
				break;
			}
		}
		
	}
	for(int i=0;i!=n;i++)
		if(!out[i])
			printf("The sheep at (%.2f, %.2f) might be eaten.\n",sp[i].x,sp[i].y);
	return 0;
}
	