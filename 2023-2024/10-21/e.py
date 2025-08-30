from math import gcd, ceil


def primesLessThan(n):
    prime = [True] * (n+1) 
    p = 2
    while (p * p <= n+1): 
        if prime[p]: 
            for i in range(p * p, n+1, p): 
                prime[i] = False
        p += 1
  
    return {i for i in range(2, n) if prime[i]}

primes = primesLessThan(10 ** 7)
for _ in range(int(input())):

    a, b = map(float, input().split())
    a = round(a * 10**5)
    b = round(b * 10**5)
    
    gcd_ = gcd(a, b)
    p, q = a // gcd_, b // gcd_

    if q == p:
        print(2, 2)
    elif p in primes and q in primes:
        print(p, q)
    else:
        print('impossible')

