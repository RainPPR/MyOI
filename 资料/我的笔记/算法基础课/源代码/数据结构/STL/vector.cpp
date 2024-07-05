// 使用vector，请尽可能减少分配次数
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
// 1. 初始化
	vector<int> a;		// 定义一个vector
	vector<int> b(10);	// 定义一个长度为10的vector
	vector<int> c(10, 3);	// 定义一个长度是10，每个元素都是3的vector
	vector<int> d[10];	// 定义10个vector(数组)
// 2. 返回元素个数	O(1)
	int len = a.size();
// 3. 返回是否为空	O(1)
	bool em = b.empty();
// 4. 清空
	b.clear();
// 5. vector的第一个元素
	int m = c.front();
// 6. vecotr的最后一个元素
	int n = c.back();
// 7. 在最后一个位置插入一个元素
	c.push_back(10);
// 8. 删掉最后一个元素
	c.pop_back();
// 9. 迭代器
	vector<int>:: iterator i = c.begin();	// 返回vector第一个元素的迭代器
	vector<int>:: iterator j = c.end();		// 返回vector最后一个元素的下一个的迭代器
// 10. 随机访问
	int s = c[1];
// 11. 比较运算（字典序）
	vector<int> f(4, 3), g(3, 4);
	cout << ((f < g) ? "Yes" : "No") << endl;
// 12. 访问vector
	vector<int> v;
	for (int i = 0 ; i < 10 ; ++i)
		v.push_back(i);
	// ① 随机访问
	for (int i = 0 ; i < v.size() ; ++i)
		cout << v[i] << " ";
	cout << endl;
	// ② 迭代器
	for (vector<int>::iterator i = v.begin() ; i != v.end() ; ++i)
		cout << *i << " ";
	cout << endl;
	// ③ auto
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}
