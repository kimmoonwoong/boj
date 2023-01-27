#include <iostream>
using namespace std;
int main(void){
    int n,m; cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        int prev = 200001;
        for (int j = k; j >0; --j) {
            int p; cin >> p;
            if (p > prev){
                cout << "No";
                return 0;
            }
            prev = p;
        }
    }
    cout << "Yes";
    return 0;
}