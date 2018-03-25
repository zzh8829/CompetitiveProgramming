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

/*

abcc

*/

struct HappyLetterDiv2
{
	char getHappyLetter(string letters)
	{
		int lt[26]={0};
		for(int i=0;i!=letters.size();i++)
			lt[letters[i]-'a']++;
		for(int i=0;i!=26;i++)
		{
			if(lt[i] && letters.size()-lt[i] < lt[i])
				return i+'a';
		}
		return '.';	
	}
};

int main()
{
	
	string s;
	cin >> s;
	cout << (new HappyLetterDiv2())->getHappyLetter(s);
	return 0;
}