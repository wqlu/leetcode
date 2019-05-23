# LeetCode

## 5. Longest Palindromic Substring

核心思想：利用dp算法，新增一个字符要同时满足两个条件才是回文

1. end letter = start letter
2. 它的[i+1][j-1]这个字串为回文

## 6. ZigZag Conversion

首先根据行数创建几个string保存在vector中，遍历字符串一次对vector中的string进行添加字符的操作，最后合成一个字符串

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

## 54. Spiral Matrix

问：螺旋遍历一个矩阵
答：首先确定四条边的位置，up就是0，down就是m-1，左边left是0，右边right是n-1；然后进入while遍历，先遍历上边，将所有元素加入ans，然后上边下移移位，如果此事上边大于下边，说明已经遍历完成，直接break。同理，对其他也是同样的操作。

## 134. Gas Station

问：顺时针走完加油站，每个加油站可以补给一定的油量和知道到达下一站所需要的油量，从哪一个加油站开始出发可以完成任务？
答：粗暴的方法：尝试从每一个加油站开始遍历，如果符合返回加油站编号，不然返回-1
另一种方法：1. 将gas_sum和cost_sum比较，如果小于cost_sum则肯定无法完成，大于则能完成
2.如能完成，遍历一次找到可以成为起点的station

## 240. Search a 2D Matrix II

问：在二维矩阵查找某一个值是否存在？
答：由于横竖都是有序的，从右上角开始比对，可以每次排除一行或一列

## 347. Top K Frequent Elements

问：返回一个数组出现次数最多的前k个数
答：首先使用unorder_map来统计出现的次数，然后使用priority_queue，由于其默认是最大堆，可以对出现次数进行排列。

## 886. Possible Bipartition

问：互相不喜欢的人不能分在一个部分里，抽象出无向图是否可分为两部分？
答：染色法，对节点进行染色，分蓝色和红色，相邻节点的颜色不同，dfs遍历下来，如果相邻颜色相同，代表冲突，无法分为两个部分。

```c++
class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
      g_ = vector<vector<int>>(N);
      for (const auto& d : dislikes) {
        g_[d[0] - 1].push_back(d[1] - 1);
        g_[d[1] - 1].push_back(d[0] - 1);
      }
      colors_ = vector<int>(N, 0);  // 0: unknown, 1: red, -1: blue
      for (int i = 0; i < N; ++i)
        if (colors_[i] == 0 && !dfs(i, 1)) return false;
      return true;      
    }
private:
  vector<vector<int>> g_;
  vector<int> colors_;
  bool dfs(int cur, int color) {
    colors_[cur] = color;
    for (int nxt : g_[cur]) {
      if (colors_[nxt] == color) return false;      
      if (colors_[nxt] == 0 && !dfs(nxt, -color)) return false;
    }
    return true;
  }
};
```
相似问题：[785. Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/)

## 973. K Closest Points to Origin

问：找到几个距离[0，0]最近的K个点
答：使用最小堆可以解决，也可以vector<pair<float， int>>来排序

```c++
// 法一
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    typedef pair<double, vector<int>> pi;
    priority_queue<pi, vector<pi>, greater<pi>> p;
    for (const auto &point : points) {
    	double distance = sqrt(pow((double)point[0], 2.0) + pow((double)point[1], 2.0));
   		p.push(make_pair(distance, point));
    }
    vector<vector<int>> ans(K);
    for (int i = 0; i < K; ++i) {
    	ans[i] = p.top().second;
    	p.pop();
    }
}
// 法二
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
	vector<vector<int>> res;
	int i;
	vector<pair <float, int>> vec1; 
	for(i=0; i< points.size(); i++)
		vec1.push_back(pair<float, int> (sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), i)); 

	sort(vec1.begin(), vec1.end()); 
	for(i=0; i<K;i++)
		res.push_back(points.at(vec1[i].second)); 

	return res;   
}
```

