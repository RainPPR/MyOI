#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int main()
{
	// 1. 初始化
	stack<int> st;
	// 2. 向栈顶插入一个元素
	st.push(50);
	// 3. 返回栈顶元素
	int t = st.top();
	// 4. 弹出栈顶元素
	st.pop();
	// 6. 返回元素个数
	int len = st.size();
	// 7. 返回是否为空
	bool e = st.empty();
	return 0;
}
