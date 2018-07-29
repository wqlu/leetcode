# -*- coding:utf-8


class Solution:
    def LeftRoateString(self, s, n):
        move = s[:n]
        left = s[n:]
        return left + move


if __name__ == '__main__':
    a = Solution()
    ans = a.LeftRoateString("helloworld", 3)
    print ans
