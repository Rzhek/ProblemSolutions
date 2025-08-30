import random

seq = [chr(ord('A') + i) for i in range(26)]
print(26, 2000)
for i in range(2000):
    print(random.randint(1, 100), end=' ')
    random.shuffle(seq)
    print(''.join(seq))
