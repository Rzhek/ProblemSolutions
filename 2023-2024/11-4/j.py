n = int(input())

def v(s):
    if s == ' ': return 0
    return ord(s) - ord('a') + 1

def v_inv(char):
    if char == 0: return ' '
    return chr(char + ord('a') - 1)

for _ in range(n):
    inp = input()
    command = inp[0]
    msg = inp[2:]

    if command == 'e':
        last = 0
        output = ''
        for i in msg:
            char = v(i)
            char += last
            char %= 27
            output += v_inv(char)
            last = char
        print(output)
    elif command == 'd':
        last = 0
        output = ''
        for i in msg:
            char = v(i)
            while char < last:
                char += 27
            newLast = char
            char = char - last
            last = newLast
            output += v_inv(char)
        print(output)
            
# 1
# d mkk in