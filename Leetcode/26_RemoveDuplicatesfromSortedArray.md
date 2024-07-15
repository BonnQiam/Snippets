#Snippet 

扩展参考 [[83_RemoveDuplicatesfromSortedList]]

# 删除有序数组中的重复项

比如说看下力扣第 26 题「[删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)」，让你在有序数组去重：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711094338.png)

函数签名如下：

```cpp
int removeDuplicates(vector<int>& nums);
```

> 所谓 ”原地修改“：如果不是原地修改的话，我们直接 `new` 一个 `int[]` 数组，把去重之后的元素放进这个新数组中，然后返回这个新数组即可。但是现在题目让你原地删除，不允许 `new` 新数组，只能在原数组上操作，然后返回一个长度，这样就可以通过返回的长度和原始数组得到我们去重后的元素有哪些了。

由于数组已经排序，所以重复的元素一定连在一起，找出它们并不难。但如果毎找到一个重复元素就立即原地删除它，由于数组中删除元素涉及数据搬移，整个时间复杂度是会达到 `O(N^2)`。

> 高效解决这道题就要用到**快慢指针**技巧：我们让慢指针 `slow` 走在后面，快指针 `fast` 走在前面探路，找到一个不重复的元素就赋值给 `slow` 并让 `slow` 前进一步。这样，就保证了 `nums[0..slow]` 都是无重复的元素，当 `fast` 指针遍历完整个数组 `nums` 后，`nums[0..slow]` 就是整个数组去重之后的结果。

# Solution

```cpp
class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    if (nums.size() == 0) {
	        return 0;
	    }
	    int slow = 0, fast = 0;
	    while (fast < nums.size()) {
	        if (nums[fast] != nums[slow]) {
	            slow++;
	            // 维护 nums[0..slow] 无重复
	            nums[slow] = nums[fast];
	        }
	        fast++;
	    }
	    // 数组长度为索引 + 1
	    return slow + 1;
	}
};
```


算法执行的过程如下 GIF 图：

![](https://labuladong.online/algo/images/%E6%95%B0%E7%BB%84%E5%8E%BB%E9%87%8D/1.gif)