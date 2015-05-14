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
#include <algorithm>

using namespace std;

int cs;

string equ;

string mult(string a, string b)
{
	string str="";
	vector<string> va,vb;
	int beg = 0;
	for(int i=0;i!=a.size();i++)
	{
		if(a[i]=='+')
		{
			va.push_back(a.substr(beg,i-beg));
			beg = i+1;
		}
	}
	va.push_back(a.substr(beg));
	beg = 0;
	for(int i=0;i!=b.size();i++)
	{
		if(b[i]=='+')
		{
			vb.push_back(b.substr(beg,i-beg));
			beg = i+1;
		}
	}
	vb.push_back(b.substr(beg));
	for(int i=0;i!=va.size();i++)
	for(int j=0;j!=vb.size();j++)
	{
		str+=va[i]+vb[j]+"+";
	}
	return str.substr(0,str.size()-1);
}
string parse(int beg,int& end);
string fact(int beg,int& end)
{
	string str="";
	if(equ[beg]=='(')
	{
		str = parse(beg+1,end);
		end++; 
	}
	else
	{	
		end = beg+1;
		str += equ[beg];
	}
	return str;
}

string term(int beg,int& end)
{
	string str = fact(beg,end);
	while(end<equ.size() && equ[end] != '+' && equ[end]!=')')
	{
		str = mult(str,fact(end,end));
	}
	return str;
}

string parse(int beg,int& end)
{
	string str = term(beg,end);
	while(equ[end]=='+')
	{
		end++;
		str += "+" + term(end,end);
	}
	return str;
}

int main()
{
	cin >> cs;
	cin.ignore();
	while(cs--)
	{
		getline(cin,equ);
		int end;
		string e = parse(0,end);
		vector<string> vs;
		int beg = 0;
		string tm;
		for(int i=0;i!=e.size();i++)
		{
			if(e[i]=='+')
			{
				tm = e.substr(beg,i-beg);
				sort(tm.begin(),tm.end());
				vs.push_back(tm);
				beg = i+1;
			}
		}
		tm = e.substr(beg);
		sort(tm.begin(),tm.end());
		vs.push_back(tm);
		sort(vs.begin(),vs.end());
		for(int i=0;i!=vs.size();i++)
		{
			if(i)cout <<"+";
			cout << vs[i];
		}
		cout << endl;
	}
	return 0;
}