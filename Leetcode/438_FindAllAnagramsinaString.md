#Snippet 

# 找所有字母异位词

这是力扣第 438 题「[找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/)」，难度中等：

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240711095419.png)

*相当于，输入一个串 `S`，一个串 `T`，找到 `S` 中所有 `T` 的排列，返回它们的起始索引*

# Solution

```cpp
vector<int> findAnagrams(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    vector<int> res; // 记录结果
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
            // 当窗口符合条件时，把起始索引加入 res
            if (valid == need.size())
                res.push_back(left);
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
    return res;
}
```

跟寻找字符串的排列 / [[567_PermutationinString]] 一样，只是找到一个合法异位词（排列）之后将起始索引加入 `res` 即可。