import sys

input = sys.stdin.readline

n = int(input())
ans = n
for i in range(1, n - 1):
    ans *= (n - i)
if(ans == 0): ans = 1
print(ans)