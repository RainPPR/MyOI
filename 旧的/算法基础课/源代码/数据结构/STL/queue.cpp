#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	// 1. ��ʼ��
	queue<int> que;
	// 2. ���β����һ��Ԫ��
	que.push(10);
	que.push(50);
	// 3. ���ض�ͷԪ��
	int f = que.front();
	// 4. ���ض�βԪ��
	int b = que.back();
	// 5. ������ͷԪ��
	que.pop();
	// 6. ����Ԫ�ظ���
	int len = que.size();
	// 7. �����Ƿ�Ϊ��
	bool e = que.empty();
	// 8. ��գ�queueû��clear����
	que = queue<int>();
	return 0;
}
