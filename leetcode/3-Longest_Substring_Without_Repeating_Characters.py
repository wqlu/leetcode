# -*- coding: utf-8
# !/usr/bin/env python

class Soulution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ansstring = []
        # substring = []
        if len(s) == 1:
            ansstring = s
        else:
            for i in range(0, len(s)-1):
                substring = []
                substring.append(s[i])
                for j in range(i, len(s) - 1):

                    if s[j+1] not in substring:
                        substring.append(s[j+1])
                        j += 1
                    else:
                        break
                if len(ansstring) < len(substring):
                    ansstring = substring
        return len(ansstring)

def solution(a):
    used = {}
    max_length = start = 0
    for i, c in enumerate(s):
        if c in used and start <= used[c]:
            start = used[c] + 1
        else:
            max_length = max(max_length, i - start + 1)

        used[c] = i
    return max_length



if __name__ == '__main__':
    # solution = Soulution()
    s = "abcabcbb"
    # ans = solution.lengthOfLongestSubstring(s)
    ans = solution(s)
    print ans


