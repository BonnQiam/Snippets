#Snippet 

# 移除元素
力扣第 27 题「[移除元素](https://leetcode.cn/problems/remove-element/)」，看下题目：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711094448.png)

函数签名如下：

```cpp
int removeElement(vector<int>& nums, int val);
```

# Solution

题目要求我们把 `nums` 中所有值为 `val` 的元素原地删除，依然需要使用快慢指针技巧：如果 `fast` 遇到值为 `val` 的元素，则直接跳过，否则就赋值给 `slow` 指针，并让 `slow` 前进一步。

这和前面说到的数组去重 / [[26_RemoveDuplicatesfromSortedArray]] 问题解法思路是完全一样的，就不画 GIF 了，直接看代码：

```cpp
class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
	    int fast = 0, slow = 0;
	    while (fast < nums.size()) {
	        if (nums[fast] != val) {
	            nums[slow] = nums[fast];
	            slow++;
	        }
	        fast++;
	    }
	    return slow;
	}
};
```

注意这里和有序数组去重的解法有一个细节差异，我们这里是先给 `nums[slow]` 赋值然后再给 `slow++`，这样可以保证 `nums[0..slow-1]` 是不包含值为 `val` 的元素的，最后的结果数组长度就是 `slow`。