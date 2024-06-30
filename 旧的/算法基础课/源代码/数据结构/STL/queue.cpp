#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int main()
{
	// 1. 初始化
	queue<int> que;
	// 2. 向队尾插入一个元素
	que.push(10);
	que.push(50);
	// 3. 返回队头元素
	int f = que.front();
	// 4. 返回队尾元素
	int b = que.back();
	// 5. 弹出队头元素
	que.pop();
	// 6. 返回元素个数
	int len = que.size();
	// 7. 返回是否为空
	bool e = que.empty();
	// 8. 清空，queue没有clear函数
	que = queue<int>();
	return 0;
}
