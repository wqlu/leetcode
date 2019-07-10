# LeetCode

## 5. Longest Palindromic Substring

核心思想：利用 dp 算法，新增一个字符要同时满足两个条件才是回文

1. end letter = start letter
2. 它的[i+1][j-1]这个字串为回文

## 6. ZigZag Conversion

首先根据行数创建几个 string 保存在 vector 中，遍历字符串一次对 vector 中的 string 进行添加字符的操作，最后合成一个字符串

## 7. Reverse Interger

注意点：翻转后的数字可能会溢出
可以使用 long 存储翻转后的数字，利用 INT32_MAX 和 INT32_MIN 辅助处理

## 8. String to Integer(atoi)

## 9. Palindrome Number

先转为 string,第一个字符为负号返回 false,再前后遍历对比字符判断

## 11. Container With Most Water

法一：暴力破解法
法二：O(n)解法，初始认为两头是最大容量的边，然后每次修改最短的边才有可能使容量变大，修改长边没有效果

## 15. 3Sum

首先对 vetor 进行排序，遍历时候将每一个当前元素作为目标元素，寻找后面 2 个数之和为目标元素的相反数，也是修改两边边界来实现。
_Key_:注意重复元素的处理，跳过处理

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

注意 erase()的使用，删除后 iter 会成为野指针

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

问：判断一个 9x9 的数独是否是有效的？  
答：判断是否有效，需要检测每一行、每一列、每一个 3x3 的格子。

1. 使用 3 个二维数组，rows、cols、box 分别存储行、列、九宫格的情况
2. 一维下标 n 分别表示：第 n 行、第 n 列、第 n 个九宫格
3. 二维下标 m 表示：在当前行、列、九宫格的数字 m
4. 二维数组的值表示该数字出现的次数，出现 1 次就代表重复了
   例如：row[2][5]代表第 2 行数字 5

## 54. Spiral Matrix

问：螺旋遍历一个矩阵  
答：首先确定四条边的位置，up 就是 0，down 就是 m-1，左边 left 是 0，右边 right 是 n-1；然后进入 while 遍历，先遍历上边，将所有元素加入 ans，然后上边下移移位，如果此事上边大于下边，说明已经遍历完成，直接 break。同理，对其他也是同样的操作。

## 67. Add Binary

问：两个二进制的字符串相加，返回它们的和（二进制字符串）  
答：对两个的索引遍历，不存在了值就取 0；对每次的操作结果移位取进位，并&1 取结果加到 ans 上（因为相加结果最多两位）；最后再次判断进位标志，倒序返回结果。

```c++
string addBinary(string a, string b) {
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    string ans;
    while (i >= 0 || j >= 0) {
    	int s = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
        carry = s >> 1;
        ans += '0' + (s & 1);
    }
    if (carry) ans += '1';
    return { rbegin(ans), rend(ans) };
}
```

## 96. Unique Binary Search Trees

问：给定一个 n，求以 1...n 为节点的二叉搜索树有多少种？  
答：假设 n 个节点存在二叉排序树的个数是 G(n),令 f(i)为以 i 为根节点的二叉搜索树的个数  
有 G(n)=f(1)+f(2)+...+f(n)  
当 i 为根节点时，左子树的节点个数为(i-1)个,而右子树的节点个数为(n-i)个,即 f(i)=G(i-1)\*G(n-i)  
所以 G(n)=G(0)**\***G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)

## 106. Construct Binary Tree from Inorder and Postorder Traversal

问：给出中序遍历和后序遍历，构造出二叉树  
答：由于后序遍历的顺序最后一个肯定是根，我们可以在中序中找到根节点的位置，将中序拆分开两个部分，分别对其调用原函数。  
对于 postorder 的左右 index 需要特别注意一下，需要计算中序划分后左边的节点个数。  
返回条件是判断左右 index 是否合理，不合理返回 NULL。

## 134. Gas Station

问：顺时针走完加油站，每个加油站可以补给一定的油量和知道到达下一站所需要的油量，从哪一个加油站开始出发可以完成任务？  
答：粗暴的方法：尝试从每一个加油站开始遍历，如果符合返回加油站编号，不然返回-1
另一种方法：1. 将 gas_sum 和 cost_sum 比较，如果小于 cost_sum 则肯定无法完成，大于则能完成 2.如能完成，遍历一次找到可以成为起点的 station

## 221. Maximal Square

问：给定一个0和1的字符矩阵，只包含1的字符矩阵的最大面积  
答：动态规划，利用dp[r][c]和周围三个值的关系

```c++
memset(square, 0, sizeof(int)*(rowSize+1)*(colSize+1));
// if (matrxit[r-1][c-1] == '1')
square[r][c] = min(min(square[r-1][c], square[r][c-1]), square[r-1][c-1]) + 1;

```

## 240. Search a 2D Matrix II

问：在二维矩阵查找某一个值是否存在？  
答：由于横竖都是有序的，从右上角开始比对，可以每次排除一行或一列

## 347. Top K Frequent Elements

问：返回一个数组出现次数最多的前 k 个数  
答：首先使用 unorder_map 来统计出现的次数，然后使用 priority_queue，由于其默认是最大堆，可以对出现次数进行排列。

## 371. Sum of Two Integers

问：不使用+-符号计算两数的和  
答：我们使用加法进行运算的时候，每位相加之后可能会有进位 carry 产生，然后在**下一位计算的时候需要加上进位一起运算**，我们可以拆开两部分进行计算：例如 759+674

1. 不考虑进位，得到 323
2. 只考虑进位，得到 1110
3. 将上面两个数相加，得到 323+1110=1433，就是最终的结果

同理，在二进制下，不考虑进位的话，0+0=0,0+1=1,1+0=1,1+1=0,这就是异或运算，只考虑进位的话 0+0=0,0+1=0,1+0=0,1+1=1,这是与运算，第三步将两者相加，递归调用此算法，终止条件是进位为 0，返回结果。  
注意：leetcode 编译器不能对负数移位，所以最高位符号必须为 0，才能左移，所以我们与 0x7fffffff，强制将最高位清 0，再进行左移。

## 378. Kth Smallest Element in a Sorted Matrix

**TODO**
[解析](https://www.cnblogs.com/grandyang/p/5727892.html)

```c++
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        const int m = matrix.size();
        vector<int> tmp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                tmp.push_back(matrix[i][j]);
            }
        }
        sort(tmp.begin(), tmp.end());
        return tmp[k - 1];
    }
};
```

## 404. Sum of Left Leaves

问：所有左叶子节点的和  
答：递归实现，本来使用了 Private：int ans;成员变量记录答案，但是答案会翻倍，不应该使用全局变量的

## 764. Largest Plus Sign

问：二维矩阵中有 1 有 0，找到以 1 为中心连成的最大十字符号？  
答：1.暴力破解法，尝试每一个位置能成的最大十字符号，记录下最大的。（事件复杂度为立方级别）  
2.四个矩阵分别记录四个方向连续的 1 的个数，然后同一位置取四个中的最小值，最后得到所有位置结果中的最大值。经优化后，可以使用一个矩阵，记录比较过的值就可以了。具体代码如下：

```c++
int orderOfLargestPlusSign_1(int N, vector<vector<int>> &mines) {
        int res = 0, cnt = 0;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        unordered_set<int> s; // 二维变成一维
        for (auto mine : mines) s.insert(mine[0] * N + mine[1]);
        for (int j = 0; j < N; ++j) {
            cnt = 0;
            for (int i = 0; i < N; ++i) { // up
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = cnt;
            }
            cnt = 0;
            for (int i = N - 1; i >= 0; --i) { // down
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int i = 0; i < N; ++i) {
            cnt = 0;
            for (int j = 0; j < N; ++j) { // left
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
            }
            cnt = 0;
            for (int j = N - 1; j >= 0; --j) { // right
                cnt = s.count(i * N + j) ? 0 : cnt + 1;
                dp[i][j] = min(dp[i][j], cnt);
                res = max(dp[i][j], res);
            }
        }
        return res;
    }
```

## 886. Possible Bipartition

问：互相不喜欢的人不能分在一个部分里，抽象出无向图是否可分为两部分？  
答：染色法，对节点进行染色，分蓝色和红色，相邻节点的颜色不同，dfs 遍历下来，如果相邻颜色相同，代表冲突，无法分为两个部分。

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

## 889. Construct Binary Tree from Preorder and Postorder Traversal

问：根据二叉树的前序和后序遍历，得到二叉树？  
答：1.遍历 pre 数组一个一个构造节点  
2.stack 保存当前树的路径  
3.对于新构造节点，如果 stack 的尾部没有左子节点，就添加上去，如果没有右子节点，就添加右子节点上  
4.如果 stack 尾节和 post 节点相同，说明我们完成了一个子树的构造，pop from stack

```c++
TreeNode* constructFromPrePost(vector<int> &pre, vector<int> &post) {
        vector<TreeNode*> s;
        s.push_back(new TreeNode(pre[0]));
        for (int i = 1, j = 0; i < pre.size(); ++i) {
            TreeNode *node = new TreeNode(pre[i]);
            while (s.back()->val == post[j]) {
                s.pop_back();
                j++;
            }
            if (s.back()->left == NULL)
                s.back()->left = node;
            else
                s.back()->right = node;
            s.push_back(node);
        }
        return s[0];
    }
```

## 973. K Closest Points to Origin

问：找到几个距离[0，0]最近的 K 个点  
答：使用最小堆可以解决，也可以 vector<pair<float， int>>来排序

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

## 984. String Without AAA or BBB

问：给出 A 和 B 字母的个数，构造出 S 来，S 满足长度为 A+B 个数，且不能出现 AAA 或 BBB  
答：假定 A 比 B 长，如果不是则交换 A 和 B，然后 while 循环，循环条件是 A 或 B 不为 0，具体如下

```c++
string strWithout3a3b(int A, int B) {
    char a = 'a';
    char b = 'b';
    if (B > A) {
        swap(A, B);
        swap(a, b);
    }
    string ans;
    while (A || B) {
        if (A > 0) { ans += a; --A; }
        if (A > B) { ans += a; --A; }
        if (B > 0) { ans += b; --B; }
    }
    return ans;
}
```

## 1041. Robot Bounded In Circle

问：一个机器人从[0,0]开始，面向上，有三种指令，分别是向前、向左转 90，向右转 90，是否会形成一个循环的路径？  
答：1.如果做了以后是原点，肯定是有环的  
2.如果没有原点，只需要半段最后的方向不是朝北的，就肯定会回到原点。具体参见[https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC++Python-Let-Chopper-Help-Explain](https://leetcode.com/problems/robot-bounded-in-circle/discuss/290856/JavaC++Python-Let-Chopper-Help-Explain)  
3.简化一下就是，考虑最后的位置为[x,y]，如果朝北就会是[2x,2y],[3x,3y]....，如果不是相当于把坐标轴转换一下，经过 4 次，就会形成一个正方形回到原点。

## 1104. Path In Zigzag Labelled Binary Tree

问：在一棵二叉树上，按“之”字型对树的节点依次标记，给出一个节点的标记，返回从根节点到该节点的路径  
答：
