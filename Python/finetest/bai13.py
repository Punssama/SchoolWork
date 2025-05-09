def count_ways(N, M):
    MOD = 1000000007  # Modulo for large counts

    # Divide N and coins by 100 to reduce problem size
    if N % 100 != 0:
        return 0  # N must be divisible by 100
    N = N // 100
    coins = [2, 5, 10, 20, 50]  # Coins divided by 100

    # dp[i][j] = ways to make sum i using j coins
    # Use a 2D array for clarity, but only need current and previous rows
    dp = [[0] * (M + 1) for _ in range(N + 1)]
    dp[0][0] = 1  # Base case: 1 way to make sum 0 with 0 coins

    # Iterate through each coin
    for coin in coins:
        for i in range(coin, N + 1):
            for j in range(1, M + 1):
                dp[i][j] = (dp[i][j] + dp[i - coin][j - 1]) % MOD

    # Sum ways to make sum N with up to M coins
    result = 0
    for j in range(M + 1):
        result = (result + dp[N][j]) % MOD

    return result


# Example usage for large input
N = 3100  # Target sum
M = 10  # Maximum number of coins
print(count_ways(N, M))
