/*
Problem ID: 239 —— maxSlidingWindow

- 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位
- 返回 滑动窗口中的最大值 

# Example 1:

输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
输出：[3,3,5,5,6,7]
解释：
滑动窗口的位置                最大值
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

# Example 2:

输入：nums = [1], k = 1
输出：[1]

*/

#include<iostream>
#include<queue>
#include<set>
using namespace std;
int main(){
	int n,k;  // n is the length of array, k is the size of window 
	cin>>n>>k; 

    // declare array a is dynamic array
    int *a = new int[n+1];
    int *ans = new int[n+1];
    
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
    deque<int> q;

	for(int i=1;i<=n;++i){
		while(!q.empty() && a[i] > a[q.back()])//队列存的是元素位置 
			q.pop_back();//删去队尾比起小的数
		q.push_back(i);//把当前位置插入队尾
		while(q.front() <= i-k)
			q.pop_front();//删去窗口外的数 
		ans[i] = a[q.front()];//队首即是最大元素的位置,将最大值存入ans
	}

	for(int i=k;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	
    return 0; 
}