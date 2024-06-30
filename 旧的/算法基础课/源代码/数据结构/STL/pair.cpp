#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	// 1. 定义
	pair<int, string> a;
	pair<int, string> b;
	// 2. 构造
	a = make_pair(10, "hi");
	b = {20, "abc"};
	// 3. first第一个元素
	int f = a.first;
	// 4. second第二个元素
	string s = b.second;
	// 支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
	cout << ((a < b) ? "Yes" : "No") << endl;
	return 0;
}
