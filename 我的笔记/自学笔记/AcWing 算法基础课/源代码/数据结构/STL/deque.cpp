// 缺点：效率极低
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>	// 包含deque、queue、vector
// 或
#include<deque>
using namespace std;
int main()
{
	// 1. 初始化
	deque<int> dq;
	// 2. 返回元素个数
	int len = dq.size();
	// 3. 返回是否为空
	bool em = dq.empty();
	// 4. 清空
	dq.clear();
	// 5. deque的第一个元素
	int m = dq.front();
	// 6. deque的最后一个元素
	int n = dq.back();
	// 7. 向最后插入一个元素
	dq.push_back(10);
	// 7. 弹出最后一个元素
	dq.pop_back();
	// 7. 向开头插入一个元素
	dq.push_front(10);
	// 7. 弹出一个元素
	dq.pop_front();
	// 9. 迭代器
	deque<int>::iterator i = dq.begin();	// 返回vector第一个元素的迭代器
	deque<int>::iterator j = dq.end();		// 返回vector最后一个元素的下一个的迭代器
	// 10. 随机访问
	int s = dq[1];
	return 0;
}
