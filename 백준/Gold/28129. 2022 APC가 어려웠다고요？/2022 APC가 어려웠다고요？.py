import sys

input = sys.stdin.readline

MOD = 10 ** 9 + 7
N = 3001
n, k = map(int, input().split())
dp = [[0] * (N) for _ in range(n)]

lasts = 0
laste = 0

for i in range(0, n):
    s, e = map(int, input().split())
    if (i == 0):
        lasts = s
        laste = e
        for j in range(s, e + 1):
            if (j > 0):
                dp[0][j] = dp[0][j - 1] + 1
            else:
                dp[0][j] = 1

    else:
        for j in range(s, e + 1):
            _min = max(j - k - 1, 0, last_s - 1)
            _max = min(j + k, N, last_e)
            dp[i][j] = (dp[i - 1][_max] - dp[i - 1][_min]) % MOD
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD
    last_s = s
    last_e = e
print(dp[-1][last_e])