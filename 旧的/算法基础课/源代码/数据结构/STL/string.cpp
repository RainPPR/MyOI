#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
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
	return 0;
}
