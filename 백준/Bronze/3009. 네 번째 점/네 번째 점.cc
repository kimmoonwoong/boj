#include <iostream>
using namespace std;
int x[3];
int y[3];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];
	int xs = x[0] ^ x[1] ^ x[2];
	int ys = y[0] ^ y[1] ^ y[2];
	cout << xs << " " << ys;
	return 0;
}