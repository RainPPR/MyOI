// ȱ�㣺Ч�ʼ���
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>	// ����deque��queue��vector
// ��
#include<deque>
using namespace std;
int main()
{
	// 1. ��ʼ��
	deque<int> dq;
	// 2. ����Ԫ�ظ���
	int len = dq.size();
	// 3. �����Ƿ�Ϊ��
	bool em = dq.empty();
	// 4. ���
	dq.clear();
	// 5. deque�ĵ�һ��Ԫ��
	int m = dq.front();
	// 6. deque�����һ��Ԫ��
	int n = dq.back();
	// 7. ��������һ��Ԫ��
	dq.push_back(10);
	// 7. �������һ��Ԫ��
	dq.pop_back();
	// 7. ��ͷ����һ��Ԫ��
	dq.push_front(10);
	// 7. ����һ��Ԫ��
	dq.pop_front();
	// 9. ������
	deque<int>::iterator i = dq.begin();	// ����vector��һ��Ԫ�صĵ�����
	deque<int>::iterator j = dq.end();		// ����vector���һ��Ԫ�ص���һ���ĵ�����
	// 10. �������
	int s = dq[1];
	return 0;
}
