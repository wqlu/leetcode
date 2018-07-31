# -*- coding:utf-8


class Solution:
    def ReverseSentence(self,s):
        """
        把单词序列翻转
        :param s:传入的单词序列
        """
        ans = ""
        s_list = s.split(" ")
        for i in s_list:
            ans = i + " " + ans
        # 去除最后的空格
        return ans[:-1]


if __name__ == "__main__":
    a = Solution()
    ans = a.ReverseSentence("I am a student.")
    print ans
