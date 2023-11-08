#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[200003][4];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    vector<long long> vecNum(n + 3, 0);
	vector<long long> vecDP(n + 3, 0);
	long long sum = 0;

	for (int i = 1;i <= n;++i)
	{
		cin >> vecNum[i];
		sum += vecNum[i];
	}

	for (int i = 3;i <= n + 2;++i)
	{
		vecDP[i] = max(vecDP[i - 1], vecDP[i - 3] + vecNum[i - 2] + vecNum[i - 1] + vecNum[i]);
	}
    
    cout << sum + vecDP[n + 2];
}