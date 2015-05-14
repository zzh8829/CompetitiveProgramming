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

char note[5000],news[10000],lnews[10000],tmp[10000];
char *sa[10000];
int len1,len2,clip;
string out;

bool cmp(const char *a,const char *b){
	return strcmp(a,b)<0;
}

int main()
{
	cin.getline(note,3000);
	len1 = strlen(note);
	while(cin.get(news[len2]))
	{
		lnews[len2] = tolower(news[len2]);
		sa[len2] = lnews+len2;
		len2++;
	}
	sort(sa,sa+len2,cmp);
	for(int i=0;i<len1;)
	{
		while(note[i] && isspace(note[i]))i++;
		if(i==len1)break;
		char*w = note+i;
		char** lb = lower_bound(sa,sa+len2,w,cmp);
		int l1 = 0,l2 = 0,len;
		char* bs = *lb;
		while(bs[l1] && bs[l1]==w[l1])l1++;
		bs = *(lb-1);
		while(bs[l2] && bs[l2]==w[l2])l2++;
		len = max(l1,l2);
		if(l1>l2)
			strncpy(tmp,*lb-lnews+news,l1);
		else
			strncpy(tmp,*(lb-1)-lnews+news,l2);
		i+=len;
		tmp[len++]='\n';tmp[len++]=0;
		out+=tmp;
		clip++;
	}
	cout << clip << endl;
	cout << out << endl;
	return 0;
}