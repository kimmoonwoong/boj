#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#define ll long long
#define pii pair<int, int>
using namespace std;

struct Info {
	string name, jaehak, winner;
	int s, a;

	bool operator<(const Info& d) const {
		return a < d.a;
	}
};

void solve() {
	int n; cin >> n;
	set<string> sets;
	vector<Info> arr(n);
	for (int i = 0; i < n; i++) {
		string name, jahak, winner;
		int s, a;
		cin >> name >> jahak >> winner >> s >> a;

		arr[i] = { name, jahak, winner, s, a };
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < n; i++) {
		if (sets.size() >= 10) break;

		if (arr[i].jaehak == "jaehak" && arr[i].winner != "winner" && (arr[i].s == -1 || arr[i].s > 3)) {
			sets.insert(arr[i].name);
		}
	}

	cout << sets.size() << "\n";
	for (auto name : sets) {
		cout << name << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
}