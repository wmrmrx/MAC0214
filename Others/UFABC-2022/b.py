x = list(map(int, input().split()))

for (i, v) in enumerate(x):
    if v == 0:
        print(i+1)

