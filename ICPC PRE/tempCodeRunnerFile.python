MOD = 998244353
MAX_Y = 4000000

# DP array to store number of ways to achieve a score
dp = [0] * (MAX_Y + 1)
dp[0] = 1  # base case, one way to achieve score 0 (do nothing)

# Precompute the number of ways to achieve each possible score
for tile in range(2, MAX_Y + 1, 2):
    for current_score in range(MAX_Y, tile - 1, -1):
        dp[current_score] = (dp[current_score] + dp[current_score - tile]) % MOD

# Reading input
t = int(input())  # number of test cases
queries = list(map(int, input().split()))

# Answering each query
for y in queries:
    print(dp[y])
