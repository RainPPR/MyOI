#include <bits/stdc++.h>

using std::vector, std::any;

class seg_t {
private:                                            // # 标记为私密
struct emm {                                        // # 使用 struct 表示区间
    int l, r;                                       //   记录区间左、右端点
    struct v;                                       //   储存的数据，包括懒标记等
}; vector<emm> a;                                   // # 线段树本体
void push_up(int k) { }                             // # 数据上传：将 k*2 和 k*2+1 两个区间合并至 k 区间
void action(int k, int v) { }                       // # 数据操作：对区间 k 执行参数为 v 的操作
void push_down(int k) { }                           // # 标记下传：将 k 的标记下传至 k*2 及 k*2+1 区间
void build(vector<any> q, int k, int l, int r) {    // # 递归建树：q 表示要建的数据
    a[k].l = l, a[k].r = r;                         //   建立节点 k 的信息
    if (l == r) { return; }                         //   将 q[l] 赋值给 a[k] 区间
    int mid = l + (r - l >> 1);                     //   将区间分为两部分
    build(q, k * 2, l, mid);                        //   递归左区间
    build(q, k * 2 + 1, mid + 1, r);                //   递归右区间
    push_up(k);                                     //   建立节点 k 的信息
} void modify(int k, int p, int q, int v) {         // # 区间修改：将区间 [p, r] 执行参数为 v 的操作
    auto &l = a[k].l, &r = a[k].r;                  //   将当前遍历到的区间拷贝下来
    if (l >= p && r <= q) {                         //   如果当前递归到的区间是要修改的区间的子区间
        action(k, v); return;                       //   执行操作
    } int mid = l + (r - l >> 1);                   //   将区间分为两部分
    if (mid >= p)     modify(k * 2, p, q, v);       //   递归左区间
    if (mid + 1 <= q) modify(k * 2 + 1, p, q, v);   //   递归右区间
    push_up(k);                                     //   修改节点 k 的信息
} int query(int k, int p, int q) {                  // # 区间查询：查询区间 [p, r] 的信息
    auto &l = a[k].l, &r = a[k].r;                  //   将当前遍历到的区间拷贝下来
    int mid = l + (r - l >> 1);                     //   将区间分为两部分
    int res;                                        //   创建变量 res 统计信息
    if (mid >= p)     res += query(k * 2, p, q);    //   递归左区间
    if (mid + 1 <= q) res += query(k * 2 + 1, p, q);//   递归右区间
    return res;                                     //   返回数据
}                                                   //   根据需要的信息修改 res 和返回类型
public:                                             // # 在此创建需要的函数，例如查询区间和之类的
};