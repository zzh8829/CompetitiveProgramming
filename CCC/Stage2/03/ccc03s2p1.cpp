#include <string>
#include <iostream>
using namespace std;

int mem[30001],pos,lvl,p;
string program="",in;

int main()
{
	while(getline(cin,in)) program+=in;
	while(p <program.size())
	{
		switch(program[p])
		{
		case '>':
			pos++;
			break;
		case '<':
			pos--;
			break;
		case '+':
			mem[pos]++;
			if(mem[pos]==256)
				mem[pos]=0;
			break;
		case '-':
			mem[pos]--;
			if(mem[pos]==-1)
				mem[pos]=255;
			break;
		case '[':
			if(mem[pos]==0)
			{
				lvl = 1;
				while(1)
				{
					p++;
					if(program[p]=='[')
						lvl++;
					if(program[p]==']')
						if(--lvl==0)
							break;
				}
			}
			break;
		case ']':
			if(mem[pos]!=0)
			{
				lvl = 1;
				while(1)
				{
					p--;
					if(program[p]==']')
						lvl++;
					if(program[p]=='[')
						if(--lvl==0)
							break;
				}
			}
			break;
		case '.':
			cout << char(mem[pos]);
			break;
		case '#':
			return 0;
			break;
		default:
			break;
		}
		p++;
	}
	return 0;
}