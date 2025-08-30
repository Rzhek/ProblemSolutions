


scores1 = list(map(int, input().split()))
scores2 = list(map(int, input().split()))
score1 = 0
score2 = 0
for i, j, k in zip(scores1, scores2, [6, 3, 2, 1, 2]):
    score1 += i * k
    score2 += j * k
print(f'{score1} {score2}') 