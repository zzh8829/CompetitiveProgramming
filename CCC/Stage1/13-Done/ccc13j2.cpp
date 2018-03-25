#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for(int i=0;i!=s.size();i++)
	{
		char c= s[i];
		if(c=='I' || c=='O' || c=='S' || c=='H' || c=='Z'||c=='X'||c=='N')
			continue;
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}