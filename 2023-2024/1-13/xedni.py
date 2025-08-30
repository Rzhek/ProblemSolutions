n = int(input())
words = [input()[::-1] for _ in range(n)]
words.sort()
print(*words, sep='\n')
