#Snippet 

# 移动零

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240715093451.png)

给你输入一个数组 `nums`，请你**原地修改**，将数组中的所有值为 0 的元素移到数组末尾，函数签名如下：

```cpp
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码不保证正确性，仅供参考。如有疑惑，可以参照我写的 java 代码对比查看。

void moveZeroes(vector<int>& nums);
```

比如说给你输入 `nums = [0,1,4,0,2]`，你的算法没有返回值，但是会把 `nums` 数组原地修改成 `[1,4,2,0,0]`。

# Solution

题目让我们将所有 0 移到最后，其实就相当于移除 `nums` 中的所有 0，然后再把后面的元素都赋值为 0 即可 —— 所以我们可以复用上一题的 `removeElement` / [[27_RemoveElement]] 函数：

```cpp
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
	    // 去除 nums 中的所有 0，返回不含 0 的数组长度
	    int p = removeElement(nums, 0);
	    // 将 nums[p..] 的元素赋值为 0
	    for (; p < nums.size(); p++) {
	        nums[p] = 0;
	    }
	}
};

int removeElement(vector<int>& nums, int val);
```