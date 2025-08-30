# n = int(input())

# finalSet = {i for i in range(1, 100)}

# for _ in range(n):
#     k = int(input())
#     allNums = {k,}
#     currentNums = {k,}
    
#     steps = 0
#     while len(finalSet.difference(allNums)) > 0:
#         steps += 1
#         newNums = set()
#         for i in currentNums:
#             newNums.update({i+1, i*3, i//2})
#             # newNums.add(i+1)
#             # newNums.add(i*3)
#             # newNums.add(i//2)
#         # newNums = set(filter(lambda x: 1 <= x <= 99, newNums))

#         allNums.update(currentNums)
#         newNums.difference_update(allNums)
#         allNums.update(newNums)
#         currentNums = newNums
#         # newNums = set()

#     # print(allNums)
#     print(steps)


def smallest_unrepresentable_value(coins):
    coins.sort()  # Sort the list of coin values in ascending order
    smallest = 1  # Initialize the smallest unrepresentable value

    for coin in coins:
        if coin <= smallest:
            smallest += coin
        else:
            break

    return smallest

# Read the number of sets of coin packages
n = int(input())

for i in range(n):
    # Read the number of different coin packages for this set
    c = int(input())
    
    # Read the values of the coin packages
    coin_values = list(map(int, input().split()))
    
    # Calculate the smallest unrepresentable value
    result = smallest_unrepresentable_value(coin_values)
    
    # Output the result for this set
    print(f"Set #{i + 1}: {result}\n")