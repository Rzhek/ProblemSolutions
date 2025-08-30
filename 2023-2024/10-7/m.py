class Char():

    def __init__(self, code, s):
        self.code = code
        self.s = s
        self.content = [[' ' for __ in range(s * 3)] for _ in range(s * 7)]
        if (code[::-1] not in ['1110111', '0010010', '1011101', '1011011', '0111010', '1101011', '1101111', '1010010', '1111111', '1111011', '1111110', '0101111', '1100101', '0011111', '1101101', '1101100']):
            return
        for index, i in enumerate(code[::-1]):
            if int(i) == 1:
                self.fill(int(index))
    
    def fill(self, i):
        if i % 3 == 0:
            self.fillRange((i // 3 * 3) * self.s, (i // 3 * 3 + 1) * self.s, 0, self.s * 3)
        elif i == 1:
            self.fillRange(self.s, self.s * 3, 0, self.s)
        elif i == 2:
            self.fillRange(self.s, self.s * 3, self.s * 2, self.s * 3)
        elif i == 4:
            self.fillRange(self.s * 4, self.s * 6, 0, self.s)
        elif i == 5:
            self.fillRange(self.s * 4, self.s * 6, self.s * 2, self.s * 3)
            

    def fillRange(self, x1, x2, y1, y2):
        for x in range(x1, x2):
            for y in range(y1, y2):
                self.content[x][y] = 'X'


def solve(s, string):
    chars = []
    output = [[] for _ in range(s * 7)]

    if len(string) % 7!= 0:
        string = '0' * (7 - len(string) % 7) + string

    for i in range(0, len(string), 7):
        chars.append(Char(string[i:i + 7], s))

    for char in chars:
        for index, i in enumerate(char.content):
            # print(i)
            output[index].append(''.join(i))

    # for i in output:
    #     print((' ' * s * 2).join(i))

    # file = open('output.txt', 'w')

    index = 0
    while True:
        res = ''
        for ind, i in enumerate(output[index]):
            if len(res) + s * 2 + len(i) > 80:
                # print(output[index][ind:])
                output.append(output[index][ind:])
                break
            elif res:
                res += ' ' * s * 2 + i
            else:
                res += i
        # file.write(res + '\n')
        print(res)
        index += 1
        if index >= len(output):
            break
        if index % (s * 7) == 0:
            print('\n' * s, end='')
            # file.write('\n' * s)

    # file.close()

if __name__ == '__main__':
    s, string = input().split()
    s = int(s)
    solve(s, string)

    # file1 = open('output.txt', 'r')
    # file2 = open('s0010.out', 'r')

    # for i, j in zip(file1.readlines(), file2.readlines()):
    #     if i!= j:
    #         print('Wrong Answer')
    #         print(f'Your answer    : {i}')
    #         print(f'Expected answer: {j}')
    # else:
    #     print('Accepted')
    # if file1.read() == file2.read():
    #     print('Accepted')
    # else:
    #     print('Wrong Answer')