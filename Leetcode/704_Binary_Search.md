#Snippet 

# 二分查找

![](https://picbed-1306742914.cos.ap-nanjing.myqcloud.com/pics/20240724164926.png)

这个场景是最简单的，可能也是大家最熟悉的，即搜索一个数，如果存在，返回其索引，否则返回 -1。

# Solution

```cpp,nums,{3,10,12}
int binarySearch(vector<int>& nums, int target) {
    int left = 0; 
    int right = nums.size() - 1; // 注意

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return mid; 
        else if (nums[mid] < target)
            left = mid + 1; // 注意
        else if (nums[mid] > target)
            right = mid - 1; // 注意
    }
    return -1;
}
```

PS. 

> 下深入探讨一下其中的细节。

## `while` 循环判定条件设置

> 问：为什么 `while` 循环的条件中是 `<=`，而不是 `<` ？

初始化 `right` 的赋值是 `nums.length - 1`，即最后一个元素的索引，而不是 `nums.length`。

>关于循环终止循环的条件 `<=` / `<` ，这二者可能出现在不同功能的二分查找中，区别是：前者相当于两端都闭区间 `[left, right]`，后者相当于左闭右开区间 `[left, right)`。因为索引大小为 `nums.length` 是越界的，所以我们把 `right` 这一边视为开区间。

我们这个算法中使用的是前者 `[left, right]` 两端都闭的区间。*这个区间其实就是每次进行搜索的区间*。什么时候应该停止搜索呢？当然，找到了目标值的时候可以终止：

```java
    if(nums[mid] == target)
        return mid;
```

> 但如果没找到，就需要 *`while` 循环终止*，然后返回 `-1`。那 `while` 循环什么时候应该终止？*搜索区间为空的时候应该终止*

- `while(left <= right)` 的终止条件是 `left == right + 1`，写成区间的形式就是 `[right + 1, right]`，或者带个具体的数字进去 `[3, 2]`，可见*这时候区间为空*，因为没有数字既大于等于 3 又小于等于 2 的吧。所以这时候 `while` 循环终止是正确的，直接返回 -1 即可。
- `while(left < right)` 的终止条件是 `left == right`，写成区间的形式就是 `[right, right]`，或者带个具体的数字进去 `[2, 2]`，*这时候区间非空*，还有一个数 2，但此时 while 循环终止了。也就是说*区间 `[2, 2]` 被漏掉了，索引 2 没有被搜索，如果这时候直接返回 `-1` 就是错误的*
	- 当然使用 `while(left < right)` 也可以，就需要打个补丁好了：

```java
    //...
    while(left < right) {
        // ...
    }
    return nums[left] == target ? left : -1;
```

## 左右指针更新方案

> 为什么 [[704_Binary_Search#Solution]]中左右指针更新方案设置为 `left = mid + 1`，`right = mid - 1`？有的代码则是设计为 `right = mid` 或者 `left = mid` —— 左右指针更新方案该如何正确设计？

答：这也是二分查找的一个难点，不过只要你能理解前面的内容，就能够很容易判断。

刚才明确了「搜索区间」这个概念，而且本算法的搜索区间是两端都闭的，即 `[left, right]`。那么当我们发现索引 `mid` 不是要找的 `target` 时，下一步应该去搜索哪里呢？

当然是去搜索区间 `[left, mid-1]` 或者区间 `[mid+1, right]` 对不对？*因为 `mid` 已经搜索过，应该从搜索区间中去除*。

## 算法缺陷

> 此算法有什么缺陷？

答：至此，你应该已经掌握了该算法的所有细节，以及这样处理的原因。但是，这个算法存在局限性。

比如说给你有序数组 `nums = [1,2,2,2,3]`，`target` 为 `2`，此算法返回的索引是 `2`，没错。但是如果我想得到 `target` 的左侧边界，即索引 `1`，或者我想得到 `target` 的右侧边界，即索引 `3`，这样的话此算法是无法处理的。

这样的需求很常见，*你也许会说，找到一个 `target`，然后向左或向右线性搜索不行吗？可以，但是不好，因为这样难以保证二分查找对数级的复杂度了*

> 这种左侧边界 / 右侧边界的二分搜索参考 [[二分搜索#寻找左侧边界的二分搜索：left_bound]]、[[二分搜索#寻找右侧边界的二分查找：right_bound]]