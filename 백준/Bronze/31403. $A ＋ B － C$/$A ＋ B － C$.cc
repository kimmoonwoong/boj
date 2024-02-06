#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    cout << stoi(s1) + stoi(s2) - stoi(s3) << "\n";
    cout << stoi(s1 + s2) - stoi(s3);
    return 0;
}