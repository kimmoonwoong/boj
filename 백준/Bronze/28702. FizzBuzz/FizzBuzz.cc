#include<iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int k = 0, idx = 0;
	for (int i = 0; i < 3; i++) {
		string s; cin >> s;
		if (s.find("Fizz") == string::npos && s.find("Buzz") == string::npos) {
			k = stoi(s);
			idx = i;
		}
	}

	k += (3 - idx);
	if (k % 3 == 0 && k % 5 == 0) cout << "FizzBuzz";
	else if (k % 3 == 0) cout << "Fizz";
	else if (k % 5 == 0) cout << "Buzz";
	else cout << k;
}