def solve():
    s = input()
    n = len(s)
    v = [0] * n

    for i in range(n):
        if s[i].isdigit():
            k = int(s[i])
            for j in range(max(0, i - k), min(i + k + 1, n)):
                v[j] += 1

    if any(i > 1 for i in v):
        print("unsafe")
    else:
        print("safe")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()