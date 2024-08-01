#Snippet 

# 字符串的排列

这是力扣第 567 题「[字符串的排列](https://leetcode.cn/problems/permutation-in-string/)」，难度中等：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711095317.png)

注意哦，输入的 `s1` 是可以包含重复字符的，所以这个题难度不小 —— 这种题目，是明显的滑动窗口算法，*相当给你一个 `S` 和一个 `T`，请问你 `S` 中是否存在一个子串，包含 `T` 中所有字符且不包含其他字符*？

# Solution

```cpp
// 判断 s 中是否存在 t 的排列
bool checkInclusion(string t, string s) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (right - left >= t.size()) {
            // 在这里判断是否找到了合法的子串
            if (valid == need.size())
                return true;
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    // 未找到符合条件的子串
    return false;
}
```

对于这道题的解法代码，基本上和最小覆盖子串 / [[76_MinimumWindowSubstring]] 一模一样，只需要改变几个地方：
1. 本题移动 `left` 缩小窗口的时机是窗口大小大于 `t.size()` 时，因为排列嘛，显然长度应该是一样的。
2. 当发现 `valid == need.size()` 时，就说明窗口中就是一个合法的排列，所以立即返回 `true`。
3. 至于如何处理窗口的扩大和缩小，和最小覆盖子串完全相同。

> 注 —— 由于这道题中 `[left, right)` 其实维护的是一个**定长**的窗口，窗口大小为 `t.size()`。因为定长窗口每次向前滑动时只会移出一个字符，所以可以把内层的 while 改成 if，效果是一样的。