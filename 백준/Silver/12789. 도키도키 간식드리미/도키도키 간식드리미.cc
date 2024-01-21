#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	stack<int> st;
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		if (k == cnt) cnt++;
		else{
			while (!st.empty()) {
				if (st.top() == cnt)
				{
					st.pop();
					cnt++;
				}
				else break;
			}
			st.push(k);
		}
	}
	while (!st.empty()) {
		if (st.top() == cnt) {
			st.pop();
			cnt++;
		}
		else break;
	}
	if (st.empty()) cout << "Nice";
	else cout << "Sad";
}