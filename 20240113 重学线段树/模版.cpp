#include <bits/stdc++.h>

using std::vector, std::any;

class seg_t {
private:                                            // # ���Ϊ˽��
struct emm {                                        // # ʹ�� struct ��ʾ����
    int l, r;                                       //   ��¼�������Ҷ˵�
    struct v;                                       //   ��������ݣ���������ǵ�
}; vector<emm> a;                                   // # �߶�������
void push_up(int k) { }                             // # �����ϴ����� k*2 �� k*2+1 ��������ϲ��� k ����
void action(int k, int v) { }                       // # ���ݲ����������� k ִ�в���Ϊ v �Ĳ���
void push_down(int k) { }                           // # ����´����� k �ı���´��� k*2 �� k*2+1 ����
void build(vector<any> q, int k, int l, int r) {    // # �ݹ齨����q ��ʾҪ��������
    a[k].l = l, a[k].r = r;                         //   �����ڵ� k ����Ϣ
    if (l == r) { return; }                         //   �� q[l] ��ֵ�� a[k] ����
    int mid = l + (r - l >> 1);                     //   �������Ϊ������
    build(q, k * 2, l, mid);                        //   �ݹ�������
    build(q, k * 2 + 1, mid + 1, r);                //   �ݹ�������
    push_up(k);                                     //   �����ڵ� k ����Ϣ
} void modify(int k, int p, int q, int v) {         // # �����޸ģ������� [p, r] ִ�в���Ϊ v �Ĳ���
    auto &l = a[k].l, &r = a[k].r;                  //   ����ǰ�����������俽������
    if (l >= p && r <= q) {                         //   �����ǰ�ݹ鵽��������Ҫ�޸ĵ������������
        action(k, v); return;                       //   ִ�в���
    } int mid = l + (r - l >> 1);                   //   �������Ϊ������
    if (mid >= p)     modify(k * 2, p, q, v);       //   �ݹ�������
    if (mid + 1 <= q) modify(k * 2 + 1, p, q, v);   //   �ݹ�������
    push_up(k);                                     //   �޸Ľڵ� k ����Ϣ
} int query(int k, int p, int q) {                  // # �����ѯ����ѯ���� [p, r] ����Ϣ
    auto &l = a[k].l, &r = a[k].r;                  //   ����ǰ�����������俽������
    int mid = l + (r - l >> 1);                     //   �������Ϊ������
    int res;                                        //   �������� res ͳ����Ϣ
    if (mid >= p)     res += query(k * 2, p, q);    //   �ݹ�������
    if (mid + 1 <= q) res += query(k * 2 + 1, p, q);//   �ݹ�������
    return res;                                     //   ��������
}                                                   //   ������Ҫ����Ϣ�޸� res �ͷ�������
public:                                             // # �ڴ˴�����Ҫ�ĺ����������ѯ�����֮���
};