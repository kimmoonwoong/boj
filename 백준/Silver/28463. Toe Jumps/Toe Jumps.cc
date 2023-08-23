#include<iostream>
#include <map>
#include <string>
using namespace std;


int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	map<string, string> mp;
	mp["S.OP."] = "T";
	mp["SI..P"] = "F";
	mp["SO..P"] = "Lz";
	mp["WP..O"] = "T";
	mp["W.IP."] = "F";
	mp["W.OP."] = "Lz";
	mp["N.PO."] = "T";
	mp["NP..I"] = "F";
	mp["NP..O"] = "Lz";
	mp["EO..P"] = "T";
	mp["E.PI."] = "F";
	mp["E.PO."] = "Lz";

	string s = "";
	string k; cin >> k;
	s += k;

	string s1, s2; cin >> s1 >> s2;
	s += s1;
	s += s2;
	if (mp.count(s) == 0) cout << "?";
	else cout << mp[s];

}