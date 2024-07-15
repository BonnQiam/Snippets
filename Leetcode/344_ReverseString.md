#Snippet 

# 反转字符串

一般编程语言都会提供 `reverse` 函数，其实这个函数的原理非常简单，力扣第 344 题「[反转字符串](https://leetcode.cn/problems/reverse-string/)」就是类似的需求，让你反转一个 `char[]` 类型的字符数组

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240715095040.png)

# Solution

```cpp
class Solution {
public:
	void reverseString(vector<char>& s) {
	    // 一左一右两个指针相向而行
	    int left = 0, right = s.size() - 1;
	    while (left < right) {
	        // 交换 s[left] 和 s[right]
	        char temp = s[left];
	        s[left] = s[right];
	        s[right] = temp;
	        left++;
	        right--;
	    }
	}
};
```