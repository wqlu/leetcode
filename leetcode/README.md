#### 5.Longest Palindromic Substring
核心思想：利用dp算法，新增一个字符要同时满足两个条件才是回文
1. end letter = start letter
2. 它的[i+1][j-1]这个字串为回文

#### 7. Reverse Interger
注意点：翻转后的数字可能会溢出
可以使用long存储翻转后的数字，利用INT32_MAX和INT32_MIN辅助处理

#### 8.String to Integer(atoi)

#### 9.Palindrome Number
先转为string,第一个字符为负号返回false,再前后遍历字符判断

#### 11.Container With Most Water
法一：暴力破解法
法二：