/*
scanning line algorithm to calculate the area of the union of rectangles
*/
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <set>
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#define mem(a, b) memset(a, b, sizeof(a))
#define inf 0x3f3f3f3f
#define N 220
#define ll long long
using namespace std;
#define lson l, m, rt << 1 // lson 是左子树
#define rson m + 1, r, rt << 1 | 1 // rson 是右子树
struct Seg
{
    double l, r, h;
    int f;
    Seg() {}
    Seg(double a, double b, double c, int d) : l(a), r(b), h(c), f(d) {}
    bool operator<(const Seg &cmp) const
    {
        return h < cmp.h;
    }
} e[N];
struct node
{
    int cnt;
    double len;
} t[N << 2];
double X[N];
void pushdown(int l, int r, int rt)
{
    // l, r是当前节点的区间
    // rt是当前节点的编号
    if (t[rt].cnt) // 当前的边被标记，就把当前的长度加上
        t[rt].len = X[r + 1] - X[l];
    else if (l == r) // 当为一个点的时候长度为0
        t[rt].len = 0;
    else // 其他情况把左右两个区间的值加上
        t[rt].len = t[rt << 1].len + t[rt << 1 | 1].len;
}
void update(int L, int R, int l, int r, int rt, int val)
{
    // L, R是要更新的区间
    // l, r是当前节点的区间
    // rt是当前节点的编号，val是要加的值
    if (L <= l && r <= R)// 
    {
        t[rt].cnt += val;   // 加上标记的值
        pushdown(l, r, rt); // 向下更新节点
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        update(L, R, lson, val);
    if (R > m)
        update(L, R, rson, val);
    pushdown(l, r, rt);
}
int main()
{
    int n, q = 1;
    double a, b, c, d;
    while (~scanf("%d", &n) && n)
    {
        mem(t, 0);
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            X[num] = a;
            e[num++] = Seg(a, c, b, 1); // 矩形下面用1来标记吗
            X[num] = c;
            e[num++] = Seg(a, c, d, -1); // 上面用-1来标记
        }
        sort(X, X + num); // 用于离散化
        sort(e, e + num); // 把矩形的边的纵坐标从小到大排序
        int m = unique(X, X + num) - X;// 去重， m 为离散化后的个数
        double ans = 0;
        for (int i = 0; i < num; i++)
        {
            // lower_bound()函数返回的是一个迭代器，指向第一个不小于e[i].l的元素
            int l = lower_bound(X, X + m, e[i].l) - X; // 找出离散化以后的值，l 是左边界
            int r = lower_bound(X, X + m, e[i].r) - X - 1;// 找出离散化以后的值，r 是右边界
            update(l, r, 0, m, 1, e[i].f);
            ans += t[1].len * (e[i + 1].h - e[i].h);
        }
        printf("Test case #%d\nTotal explored area: %.2lf\n\n", q++, ans);
    }
    return 0;
}