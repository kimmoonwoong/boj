#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;



int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s1, s2;
    string rs1, rs2;
    cin >> s1;
    cin >> s2;
    rs1 = s1;
    rs2 = s2;
    reverse(rs1.begin(), rs1.end());
    reverse(rs2.begin(), rs2.end());
    if (s1 + rs2 == "HEPC")
        cout << "YES";
    else if (s1.substr(0, 1) + s2 + s1.substr(1, 1) == "HEPC")
        cout << "YES";
    else if (rs1 + s2 == "HEPC")
        cout << "YES";
    else if (s1.substr(1,1) + rs2 + s1.substr(0, 1) == "HEPC")
        cout << "YES";
    else if (rs2 + s1 == "HEPC")
        cout << "YES";
    else if (s2.substr(1, 1) + rs1 + s2.substr(0, 1) == "HEPC")
        cout << "YES";
    else if (s2 + rs1 == "HEPC")
        cout << "YES";
    else if (s2.substr(0, 1) + s1 + s2.substr(1, 1) == "HEPC")
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
