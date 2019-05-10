# LeetCode

## 5. Longest Palindromic Substring

核心思想：利用dp算法，新增一个字符要同时满足两个条件才是回文

1. end letter = start letter
2. 它的[i+1][j-1]这个字串为回文

## 7. Reverse Interger

注意点：翻转后的数字可能会溢出
可以使用long存储翻转后的数字，利用INT32_MAX和INT32_MIN辅助处理

## 8. String to Integer(atoi)

## 9. Palindrome Number

先转为string,第一个字符为负号返回false,再前后遍历对比字符判断

## 11. Container With Most Water

法一：暴力破解法
法二：O(n)解法，初始认为两头是最大容量的边，然后每次修改最短的边才有可能使容量变大，修改长边没有效果

## 15. 3Sum

首先对vetor进行排序，遍历时候将每一个当前元素作为目标元素，寻找后面2个数之和为目标元素的相反数，也是修改两边边界来实现。
*Key*:注意重复元素的处理，跳过处理

## 16. 3Sum Closest

```c++
int threeSumCloest(vector<int>& nums, int target) {
    if (nums.size() < 3) return 0;
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int first = 0; first < nums.size() - 2; ++first) {
        int second = first + 1;
        int third = nums.size() - 1;
        while (second < third) {
        	int curSum = nums[first] + nums[second] + nums[third];
            if (curSum == target)
                return curSum;
    		if (abs(target - curSum) < abs(target - closest))
                closest = curSum;
            if (curSum > target) {
   				--third;
            } else {
            	++second;
            }
        }
    }
    return closest;
}
```

## 26. Remove Duplicates from Sorted Array

注意erase()的使用，删除后iter会成为野指针

## 27. Remove Element

```c++
int removeElement2(vector<int>& nums, int val) {
    int i = 0, j = 0;
    while (j < nums.size()) {
        if (nums[j] != val) {
            nums[i] = nums[j];
            i++;
        }
        j++;
    }
    return i;
}
```

## 36. Valid Sudoku

问：判断一个9x9的数独是否是有效的？
答：判断是否有效，需要检测每一行、每一列、每一个3x3的格子。
1. 使用3个二维数组，rows、cols、box分别存储行、列、九宫格的情况
2. 一维下标n分别表示：第n行、第n列、第n个九宫格
3. 二维下标m表示：在当前行、列、九宫格的数字m
4. 二维数组的值表示该数字出现的次数，出现1次就代表重复了
例如：row[2][5]代表第2行数字5

## 240. Search a 2D Matrix II

问：在二维矩阵查找某一个值是否存在？
答：由于横竖都是有序的，从右上角开始比对，可以每次排除一行或一列

