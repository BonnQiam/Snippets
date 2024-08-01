/*
scanning line algorithm to calculate the intersection of the rectangles
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
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
#define N 2200
#define ll long long
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Seg
{
	double l,r,h;
	int f;
	Seg() {}
	Seg(double a,double b,double c,int d):l(a),r(b),h(c),f(d) {}
	bool operator < (const Seg &cmp) const
	{
		return h<cmp.h;
	}
} e[N];
struct node
{
	int cnt;
	double len,s;// cnt是标记，len是长度，s是被标记的长度 —— s 被用来计算交集
} t[N<<2];
double X[N];
void pushdown(int l,int r,int rt)
{
	// l, r是当前节点的区间
	// rt是当前节点的编号

	if(t[rt].cnt)
		t[rt].len=X[r+1]-X[l];//覆盖一次以及以上
	else if(l==r)
		t[rt].len=0;
	else
		t[rt].len=t[rt<<1].len+t[rt<<1|1].len;

	if(t[rt].cnt>1)//覆盖两次以及以上
		t[rt].s=X[r+1]-X[l];
	else if(l==r)
		t[rt].s=0;
	else if(t[rt].cnt==1)//覆盖一次
		t[rt].s=t[rt<<1].len+t[rt<<1|1].len;//两个子节点的长度之和，每个子节点的长度是覆盖一次以及以上，这样就实现了覆盖两次以及以上的长度
	else
		t[rt].s=t[rt<<1].s+t[rt<<1|1].s;
}
void update(int L,int R,int l,int r,int rt,int val)
{
	// L, R是要更新的区间，
	// l, r是当前节点的区间
	// rt是当前节点的编号，val是要加的值
	if(L<=l&&r<=R)
	{
		t[rt].cnt+=val;
		pushdown(l,r,rt);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m) update(L,R,lson,val);
	if(R>m) update(L,R,rson,val);
	pushdown(l,r,rt);
}
int main()
{
	int n,q;
	double a,b,c,d;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		mem(t,0);
		int num=0;
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
			X[num]=a;
			e[num++]=Seg(a,c,b,1);
			X[num]=c;
			e[num++]=Seg(a,c,d,-1);
		}
		sort(X,X+num);
		sort(e,e+num);
		int m=unique(X,X+num)-X;
		double ans=0;
		for(int i=0; i<num; i++)
		{
			int l=lower_bound(X,X+m,e[i].l)-X;
			int r=lower_bound(X,X+m,e[i].r)-X-1;
			update(l,r,0,m,1,e[i].f);
			ans+=t[1].s*(e[i+1].h-e[i].h);//
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}