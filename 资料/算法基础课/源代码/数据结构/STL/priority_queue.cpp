#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	// 1. ��ʼ��
	priority_queue<int, vector<int>, less<int>> q1;    // ����ѣ�Ĭ�ϣ�
	priority_queue<int, vector<int>, greater<int>> q2; // С����
	// 2. ����һ��Ԫ��
	q1.push(50);
	// 3. ���ضѶ�Ԫ��
	int t = q1.top();
	// 4. �����Ѷ�Ԫ��
	q1.pop();
	// 6. ����Ԫ�ظ���
	int len = q1.size();
	// 7. �����Ƿ�Ϊ��
	bool e = q1.empty();
	return 0;
}
