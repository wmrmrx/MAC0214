N = int(input())
C = sum(map(int, input().split()))
V = sum(map(int, input().split()))

if C == V:
    print("Sim")
else:
    print("Nao")

