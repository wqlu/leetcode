import sys


def move(s):
    for i in range(len(s)):
        if s[i].islower():
            j = i
            while j > 0 and s[j-1].isupper():
                tmp = s[j-1]
                s[j-1] = s[j]
                s[j] = tmp
                j -= 1
    return ''.join(s)

if __name__ == '__main__':
    while True:
        mystr = sys.stdin.readline().strip()
        if len(mystr) == 0:
            break
        print move(list(mystr))
