N = int(input())
C = list(map(int, input().split()))

ans = int(1e18)

for i in range(1,101):
    cur = 0
    for x in C:
        cur += (x - i)*(x -i)
    ans  = min(cur, ans)

print(ans)


