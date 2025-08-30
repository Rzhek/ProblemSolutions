n = int(input())

scores = []
for _ in range(n):
    scores.append(int(input()))

left = 1
right = n-2
sum1 = sum(scores[:left])
sum2 = sum(scores[right+1:])
min_score = (sum1+sum2) / (left + n - right - 1)

while left < right:
    if scores[left] < scores[right]:
        # include left
        sum1 += scores[left]
        left += 1
    else:
        sum2 += scores[right]
        right -= 1
    
    # print(sum1, sum2, left, right)
    # input()
    min_score = min(min_score, (sum1+sum2) / (left + n - right - 1))

print(round(min_score, 3))





# 5
# 5
# 1
# 7
# 8
# 2