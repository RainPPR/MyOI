#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	// 1. 初始化
	priority_queue<int, vector<int>, less<int>> q1;    // 大根堆（默认）
	priority_queue<int, vector<int>, greater<int>> q2; // 小根堆
	// 2. 插入一个元素
	q1.push(50);
	// 3. 返回堆顶元素
	int t = q1.top();
	// 4. 弹出堆顶元素
	q1.pop();
	// 6. 返回元素个数
	int len = q1.size();
	// 7. 返回是否为空
	bool e = q1.empty();
	return 0;
}
