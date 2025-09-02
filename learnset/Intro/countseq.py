for _ in range(int(input())):
    word1 = input()
    word2 = input()
    n, m = len(word1), len(word2)

    dp = [[0] * (n + 1) for __ in range(m + 1)]
    for i in range(n + 1):
        dp[0][i] = 1
    
    for r in range(1, m + 1):
        for c in range(1, n + 1):
            if word1[c-1] == word2[r-1]:
                dp[r][c] = dp[r-1][c-1] + dp[r][c-1]
            else:
                dp[r][c] = dp[r][c-1]
    
    print(dp[-1][-1])