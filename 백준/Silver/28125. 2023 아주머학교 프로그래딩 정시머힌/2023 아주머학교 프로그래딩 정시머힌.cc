#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
map<string, string> changechar;
int main() {
	int n; cin >> n;
	changechar.insert({ "@", "a"});
	changechar.insert({ "[", "c" });
	changechar.insert({ "!", "i" });
	changechar.insert({ ";", "j" });
	changechar.insert({ "^", "n" });
	changechar.insert({ "0", "o" });
	changechar.insert({ "7", "t" });
	changechar.insert({ "\\'", "v" });
	changechar.insert({ "\\\\'", "w" });

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int cnt = 0;
		int sec = 0;
		int thred = 0;
		string ans = "";
		for (int i = 0; i < s.length(); i++) {
			bool check = false;
			auto item = changechar.find(s.substr(i, 1));
			if (item != changechar.end()) {
				ans += item->second;
				cnt++;
				check = true;
			}
			
			if (i < s.length() - 1) {
				auto item2 = changechar.find(s.substr(i, 2));
				if (item2 != changechar.end()) {
					ans += item2->second;
					cnt++;
					i++;
					check = true;
					sec++;
				}
			}
			if (i < s.length() - 2) {
				auto item3 = changechar.find(s.substr(i, 3));
				if (item3 != changechar.end()) {
					ans += item3->second;
					cnt++;
					check = true;
					i += 2;
					thred++;
				}
			}

			if (!check) ans += s.substr(i, 1);
		}
		if (cnt >=ans.length() / 2.0 ) cout << "I don't understand\n";
		else cout << ans << "\n";
	}
}
