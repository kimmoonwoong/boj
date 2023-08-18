#include<iostream>
#include <string>
#include <set>
using namespace std;


int main(void)
{
	string arr[4];
	cin >> arr[0] >> arr[1];
	cin >> arr[2] >> arr[3];
	set<string> s;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			string k = arr[i] + " " + arr[j];
			s.insert(k);
		}
	}
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		cout << *iter << "\n";
	}
}