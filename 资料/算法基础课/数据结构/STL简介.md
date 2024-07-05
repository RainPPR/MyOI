# STL简介
## C++ STL 简介
### vector：变长数组，倍增的思想
```cpp
// 使用vector，请尽可能减少分配次数
// 0. 头文件
	#include<vector>
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
	vector<int>::iterator i = c.begin();	// 返回vector第一个元素的迭代器
	vector<int>::iterator j = c.end();		// 返回vector最后一个元素的下一个的迭代器
// 10. 随机访问
	int s = c[1];
// 11. 比较运算（字典序）
	vector<int> f(4, 3), g(3, 4);
	cout << ((f < g) ? "Yes" : "No") << endl;
// 12. 访问vector
	vector<int> v;
	for (int i = 0 ; i < 10 ; ++i)
		v.push_back(i);
// 随机访问
	for (int i = 0 ; i < v.size() ; ++i)
		cout << v[i] << " ";
	cout << endl;
// 迭代器
	for (vector<int>::iterator i = v.begin() ; i != v.end() ; ++i)
		cout << *i << " ";
	cout << endl;
// auto
	for (auto x : v)
		cout << x << " ";
	cout << endl;
```
### pair：二位元组
```cpp
// 0. 头文件
	#include<algorithm>
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
// 5. 支持比较运算，以first为第一关键字，以second为第二关键字（字典序）
	cout << ((a < b) ? "Yes" : "No") << endl;
```
### string：字符串
```cpp
// 1. 初始化
	string s1 = "hi";
	string s2("bye");
// 2. 返回字符串长度
	int a = s1.size();
	int b = s2.length();
// 3. 返回字符串是否为空
	bool e = s1.empty();
// 4. 清空字符串
	s1.clear();
// 5. 返回子串
	string ss = s2.substr(1, 2);	// 起始下标，子串长度；子串长度过长自动忽略；省略子串长度，返回从起始下标开始到字符串结尾的子串
	s1.c_str();						// 返回字符串所在字符数组的起始地址
// 6. 向字符串结尾添加
	s2 += ", dog.";
// 7. 输出
	cout << s2 << endl;
	printf("%s\n", s2.c_str());	// c_str() 返回字符串所在字符数组的起始地址
```
### queue：队列
```cpp
// 0. 头文件
	#include<queue>
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
```
### priority_queue：优先队列（堆），默认是大根堆
```cpp
// 0. 头文件
	#include<queue>
	#include<vector>
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
```
### stack：栈
```cpp
// 0. 头文件
	#include<stack>
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
```
### deque：双端队列（队头队尾都可以插入，可以访问任意元素）
```cpp
// 缺点：效率极低
// 0. 头文件
	#include<queue>	// 包含deque、queue、vector
	#include<deque>
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
```
### set, map, multiset, multimap：基于平衡二叉树（红黑树），动态维护有序序列
```cpp
size()
empty()
clear()
begin() / end()
++, -- // 返回前驱和后继，时间复杂度 O(logn)
```
#### set / multiset（有重复）
```cpp
insert()  // 插入一个数
find()    // 查找一个数
count()   // 返回某一个数的个数
erase()
    (1) 输入是一个数 x，删除所有 x
    (2) 输入一个迭代器，删除这个迭代器
lower_bound(x)  // 返回大于等于 x 的最小的数的迭代器
upper_bound(x)  // 返回大于 x 的最小的数的迭代器
```
#### map / multimap（有重复）
```cpp
insert()  // 插入的数是一个 pair
erase()   // 输入的参数是 pair 或者迭代器
find()
[]        // 注意 multimap 不支持此操作
lower_bound(x)  // 返回大于等于 x 的最小的数的迭代器
upper_bound(x)  // 返回大于 x 的最小的数的迭代器
```
### unordered_set, unordered_map, unordered_multiset, unordered_multimap（有重复）：哈希表（没有顺序）
和上面类似，增删改查的时间复杂度是 $O(1)$
不支持 `lower_bound()` / `upper_bound()`， 迭代器的 `++`，`--`
### bitset, 圧位
```cpp
bitset<10000> s;
~, &, |, ^
>>, <<
==, !=
[]
count()    // 返回有多少个1
any()	    // 判断是否至少有一个1
none()	    // 判断是否全为0
set()	    // 把所有位置成1
set(k, v)	// 将第k位变成v
reset()	// 把所有位变成0
flip()	    // 等价于~
flip(k)	 // 把第k位取反
```