#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
	// 1. ��ʼ��
	stack<int> st;
	// 2. ��ջ������һ��Ԫ��
	st.push(50);
	// 3. ����ջ��Ԫ��
	int t = st.top();
	// 4. ����ջ��Ԫ��
	st.pop();
	// 6. ����Ԫ�ظ���
	int len = st.size();
	// 7. �����Ƿ�Ϊ��
	bool e = st.empty();
	return 0;
}
