from collections import Counter


c = 1
while True:
    w1 = input()
    w2 = input()
    if (w1 == "END" and w2 == "END"):
        exit()
    c1 = Counter(w1)
    c2 = Counter(w2)
    print(f"Case {c}: {"same" if c1 == c2 else "different"}")
    c += 1