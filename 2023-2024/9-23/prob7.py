from collections import defaultdict


n = int(input())

hashtags = defaultdict(int);

for j in range(n):
    for i in input().split():
        if i.startswith('#'):
            if not i[-1].isalpha():
                i = i[:-1]
            hashtags[i.lower()[1:]] += 1
    if j != n-1:
        input()

for i in sorted(hashtags, key=lambda x: (-hashtags[x], x)):
    print(f'{hashtags[i]} {i}')

            


# 8
# Friendly reminder... batteries are not imported from the North Pole.  #Christmas #Shopping
# Santa is the man and he's got a plan I'm his biggest fan and he's coming at #Christmas #WalnutCreekStuff
# It's Saturday night...who's watching the #SNL #Christmas episode?
# So excited for #Christmas even though it doesn't feel like #Christmas
# Baileys #Christmas party was great. @GableBailey pic.twitter.com/eRUHQazM9G
# Guys #Christmas is 3 days away!! Christmas is #soClose
# All i want for #christmas is, #food.
# Russ Rose would like to wish you all a Merry #Christmas without smiling. #SNL
