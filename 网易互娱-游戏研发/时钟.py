#!/usr/bin/python
# -*- coding:utf-8

class Solution:
    def min_time(self, time):
        hour = int(time[0:2])
        mint = int(time[3:5])
        secd = int(time[6:8])
        if 0 <= hour and hour <= 23 and 0 <= mint and mint <=59 and 0 <= secd and secd <= 59:
            return time
        if hour > 23:
            hour = "0" + str(hour)[1:]
        elif hour < 10:
            hour = "0"+ str(hour)
        if mint > 59:
            mint = "0" + str(mint)[1:]
        elif mint < 10:
            mint = "0"+ str(mint)
        if secd > 59:
            secd = "0" + str(secd)[1:]
        elif secd < 10:
            secd = "0" + str(secd)
        return str(hour)+":"+str(mint)+":"+str(secd)


if __name__ == "__main__":
    number = int(raw_input())
    ans = []
    solution = Solution()
    for i in range(0, number):
        string = raw_input()
        after_time = solution.min_time(string)
        ans.append(after_time)
    for i in ans:
        print i 
