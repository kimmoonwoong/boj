import sys
# from collections import deque
# import math

input = sys.stdin.readline

n = int(input())

n_list = [0] * (n + 1)

for i in range(2, n + 1) :
    n_list[i] = n_list[i - 1] + 1

    if i % 2 == 0 :
        n_list[i] = min(n_list[i], n_list[i // 2] + 1)
    if i % 3 == 0 :
        n_list[i] = min(n_list[i], n_list[i // 3] + 1)
        

print(n_list[n])