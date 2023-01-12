#include <algorithm>
#include <iostream>
using namespace std;
int maxdp[3];
int mindp[3];
int main() {
    int n; cin >> n;
    int k,l,p; cin >> k >> l >> p;
    maxdp[0] = k; maxdp[1] = l; maxdp[2] = p;
    mindp[0] = k; mindp[1] = l; mindp[2] = p;

    for(int i = 1;i<n;i++){
        int a,b,c; cin >> a >> b >> c;
        int temp_0 = maxdp[0]; int temp_1 = maxdp[1]; int temp_2 = maxdp[2];
        maxdp[0] = max(temp_0 + a, temp_1 + a);
        maxdp[1] = max(temp_2 + b, max(temp_0 + b, temp_1 + b));
        maxdp[2] = max(temp_1 + c, temp_2 + c);
        temp_0 = mindp[0]; temp_1 = mindp[1]; temp_2 = mindp[2];
        mindp[0] = min(temp_0 + a, temp_1 + a);
        mindp[1] = min(temp_2 + b, min(temp_0 + b, temp_1 + b));
        mindp[2] = min(temp_1 + c, temp_2 + c);
    }

    cout << max(maxdp[0], max(maxdp[1], maxdp[2])) << " " << min(mindp[0], min(mindp[1], mindp[2]));

    return 0;
}