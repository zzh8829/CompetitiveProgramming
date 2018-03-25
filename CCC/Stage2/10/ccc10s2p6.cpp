#include <iostream>
#include <string>
using namespace std;

char key[128];
string keys[128],msg;
int n;

void getKeys(char i)
{
	keys[i] = i;
	char nxt = key[i];
	while(nxt != i)
	{
		keys[i]+=nxt;
		nxt = key[nxt];	
	}
}

int main()
{
	for(int i='A';i<='Z';i++)
		cin >> key[i];
	cin >> key['_'] >> n >> msg;
	for(int i='A';i<='Z';i++)
		getKeys(i);
	getKeys('_');
	for(int i=0;i!=msg.size();i++)
		msg[i] = keys[msg[i]][n%keys[msg[i]].size()];
	cout << msg << endl;
}