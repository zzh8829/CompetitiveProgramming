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

int n,k,p,o;
vector<int> ve;
vector<int> vo;

typedef pair<int,int> I2;

int main()
{
	scanf("%d %d %d",&n,&k,&p);
	o = k-p;
	for(int i=0;i!=n;i++) {
		int a;
		scanf("%d",&a);
		if(a%2==0) {
			ve.push_back(a);
		} else {
			vo.push_back(a);
		}
	}
	if(vo.size() < o || n < p+o){
		cout << "NO" << endl;
	} else if(vo.size() == o) {
		cout << "YES" << endl;
		for(int i=0;i!=vo.size();i++)
			cout << "1 " << vo[i] << endl;
		for(int i=0;i!=p-1;i++) 
			cout << "1 " << ve[i] << endl;
		cout << ve.size()-p+1;
		for(int i=p-1;i!=ve.size();i++)
			cout << " " << ve[i];
		cout << endl;
	} else {
		int numo = vo.size() - o;
		if(numo % 2 != 0) {
			cout << "NO" << endl;
		} else {
			if(numo/2 + ve.size() < p) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
				for(int i=0;i!=o;i++) {
					cout << "1 " << vo[i] << endl;
				}
				vector<I2> vi2;
				for(int i=o;i!=vo.size();i+=2) {
					vi2.push_back(I2(vo[i],vo[i+1]));
				}
				if(p <= vi2.size()) {
					for(int i=0;i!=p-1;i++) {
						cout << "2 " << vi2[i].first << " " << vi2[i].second << endl;
					}
					cout << ve.size() + 2*(p-vi2.size()+1);
					for(int i=p-1;i!=vi2.size();i++) {
						cout << " " << vi2[i].first << " " << vi2[i].second;
					}
					for(int i=0;i!=ve.size();i++) {
						cout << " " << ve[i];
					}
					cout << endl;
				} else {
					for(int i=0;i!=vi2.size();i++) {
						cout << "2 " << vi2[i].first << " " << vi2[i].second << endl;
					}
					p -= vi2.size();
					for(int i=0;i!=p-1;i++) 
						cout << "1 " << ve[i] << endl;
					cout << ve.size()-p+1;
					for(int i=p-1;i!=ve.size();i++)
						cout << " " << ve[i];
					cout << endl;
				}
			}
		}
	}
	return 0;
}