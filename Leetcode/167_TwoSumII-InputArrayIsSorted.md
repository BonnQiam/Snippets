#Snippet 

# 两数之和

看下力扣第 167 题「[两数之和 II](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)」：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711094650.png)

# Solution

只要数组有序，就应该想到双指针技巧。这道题的解法有点类似二分查找 / 
[[二分查找]] ，通过调节 `left` 和 `right` 就可以调整 `sum` 的大小：

```cpp
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
	    // 一左一右两个指针相向而行
	    int left = 0, right = nums.size() - 1;
	    while (left < right) {
	        int sum = nums[left] + nums[right];
	        if (sum == target) {
	            // 题目要求的索引是从 1 开始的
	            return {left + 1, right + 1};
	        } else if (sum < target) {
	            left++; // 让 sum 大一点
	        } else if (sum > target) {
	            right--; // 让 sum 小一点
	        }
	    }
	    return {-1, -1};
	}
};
```

我在另一篇文章 [一个函数秒杀所有 nSum 问题](https://labuladong.online/algo/practice-in-action/nsum/) 中也运用类似的左右指针技巧给出了 `nSum` 问题的一种通用思路，这里就不做赘述了。