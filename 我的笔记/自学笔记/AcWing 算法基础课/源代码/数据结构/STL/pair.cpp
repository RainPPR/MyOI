#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	// 1. ����
	pair<int, string> a;
	pair<int, string> b;
	// 2. ����
	a = make_pair(10, "hi");
	b = {20, "abc"};
	// 3. first��һ��Ԫ��
	int f = a.first;
	// 4. second�ڶ���Ԫ��
	string s = b.second;
	// ֧�ֱȽ����㣬��firstΪ��һ�ؼ��֣���secondΪ�ڶ��ؼ��֣��ֵ���
	cout << ((a < b) ? "Yes" : "No") << endl;
	return 0;
}
