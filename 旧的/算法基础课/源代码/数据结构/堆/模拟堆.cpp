#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010;

int n, m;
int h[N],	// 数组模拟堆
    ph[N],	// 第i个插入的数的下标
    hp[N],	// 堆里的第i个点是第几个插入的点
    sz;		// 堆的大小

void SWAP(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void heap_swap(int a, int b)
{
	SWAP(ph[hp[a]], ph[hp[b]]);
	SWAP(hp[a], hp[b]);
	SWAP(h[a], h[b]);
}

void down(int u)
{
	int t = u;
	if ((u * 2 <= sz) && (h[u * 2] < h[t]))
		t = u * 2;
	if ((u * 2 + 1 <= sz) && (h[u * 2 + 1] < h[t]))
		t = u * 2 + 1;
	if (u != t)
	{
		heap_swap(u, t);
		down(t);
	}
}

void up(int u)
{
	while ((u >> 1) && (h[u >> 1] > h[u]))
	{
		heap_swap(u >> 1, u);
		u >>= 1;
	}
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		char op[10];
		scanf("%s", op);
		int k, x;
		if (!strcmp(op, "I"))
		{
			scanf("%d", &x);
			++sz, ++m;
			ph[m] = sz, hp[sz] = m;
			h[sz] = x;
			up(sz);
		}
		else if (!strcmp(op, "PM"))
		{
			printf("%d\n", h[1]);
		}
		else if (!strcmp(op, "DM"))
		{
			heap_swap(1, sz--);
			down(1);
		}
		else if (!strcmp(op, "D"))
		{
			scanf("%d", &k);
			k = ph[k];
			heap_swap(k, sz--);
			up(k), down(k);
		}
		else
		{
			scanf("%d %d", &k, &x);
			k = ph[k];
			h[k] = x;
			up(k), down(k);
		}
	}
	return 0;
}
