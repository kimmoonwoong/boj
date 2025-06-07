#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>
#include <cmath>
using namespace std;

bool doubleEquals(double a, double b, double epsilon = 1e-9) {
    bool l = std::fabs(a - b) < epsilon;
    
    return std::fabs(a - b) < epsilon;
}

bool comp(tuple<double, int, string> &t1, tuple<double, int, string> &t2) {
    if (doubleEquals(get<0>(t1),get<0>(t2))) {
        if (get<1>(t1) == get<1>(t2)) {
            return get<2>(t1) < get<2>(t2);
        }
        else {
            return get<1>(t1) < get<1>(t2);
        }
    }
    else {
        return get<0>(t1) > get<0>(t2);
    }
}



int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    vector<tuple<double, int, string>> v1;
    for (int i = 0; i < n; i++) {
        string name;
        int s, r, c; cin >> name >> s >> r >> c;

        double score = floor(pow(s, 3) / (c * (r + 1)));
        v1.push_back({ score, c, name });
    }
    sort(v1.begin(), v1.end(), comp);

    cout << get<2>(v1[1]);

    return 0;
}
