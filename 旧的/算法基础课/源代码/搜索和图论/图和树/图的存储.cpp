#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100010,	// ����������м�������
          M = N * 2;	// �ߵ�����������Ľ��������
int h[N],	// i�Ž���Ӧ�������ͷ
    e[M],	// ��һ�����ָ��ĵ�
    ne[M],	// ��һ�������±�
    idx;	// �������
// ��ʼ��
void init()
{
	idx = 0;
	memset(h, -1, sizeof(h));
}
// ����һ��aָ��b��
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
// ����һ�� a <-> b �ı�
void add_double(int a, int b)
{
	add(a, b);
	add(b, a);
}
// ����xָ������бߣ����ظ���
int geteg(int x)
{
	int count = 0;
	for (int i = h[x] ; i != -1 ; i = ne[i])
	{
		// ��ʱ������һ���ߣ�x -> e[i]
		count++;
		// ��������
	}
	return count;
}
int main()
{
	init();
	return 0;
}
