from collections import defaultdict


def update(emp, price):
    value[emp] += price
    for i in dependencies[emp]:
        update(i, price)

for compNum  in range(1, int(input())+1):
    
    value = defaultdict(int)
    dependencies = defaultdict(list)
    t = int(input())

    print(f'COMPANY {compNum}')
    for _ in range(t):
        inp = input().split()

        if inp[0] == 'ADD':
            emp1 = inp[1]
            emp2 = inp[2]
            if emp1 != 'ROOT':
                dependencies[emp2].append(emp1)
        elif inp[0] == 'SALE':
            emp = inp[1]
            price = int(inp[2])
            update(emp, price)
        elif inp[0] == 'QUERY':
            print(value[inp[1]])
