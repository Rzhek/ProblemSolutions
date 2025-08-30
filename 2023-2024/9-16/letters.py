# num = 1
# while True:
#     s1 = input()
#     s2 = input()
#     if s1 == s2 == "END":
#         break
    
#     if sorted(s1) == sorted(s2):
#         res = "same"
#     else:
#         res = "different"
    
#     print(f"Case {num}: {res}")
#     num += 1

import sys

def count_letters(s):
    letter_count = {}
    for letter in s:
        if letter in letter_count:
            letter_count[letter] += 1
        else:
            letter_count[letter] = 1
    return letter_count

def are_strings_same_letters(s1, s2):
    letter_count1 = count_letters(s1)
    letter_count2 = count_letters(s2)
    return letter_count1 == letter_count2

case_number = 1

for line in sys.stdin:
    if line.strip().upper() == "END":
        break

    string1 = line.strip()
    string2 = input().strip()  # Read the next line for the second string

    result = "same" if are_strings_same_letters(string1, string2) else "different"
    print(f"Case {case_number}: {result}")
    case_number += 1