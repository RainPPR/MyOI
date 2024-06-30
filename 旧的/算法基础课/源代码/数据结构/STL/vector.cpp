// ʹ��vector���뾡���ܼ��ٷ������
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
// 1. ��ʼ��
	vector<int> a;		// ����һ��vector
	vector<int> b(10);	// ����һ������Ϊ10��vector
	vector<int> c(10, 3);	// ����һ��������10��ÿ��Ԫ�ض���3��vector
	vector<int> d[10];	// ����10��vector(����)
// 2. ����Ԫ�ظ���	O(1)
	int len = a.size();
// 3. �����Ƿ�Ϊ��	O(1)
	bool em = b.empty();
// 4. ���
	b.clear();
// 5. vector�ĵ�һ��Ԫ��
	int m = c.front();
// 6. vecotr�����һ��Ԫ��
	int n = c.back();
// 7. �����һ��λ�ò���һ��Ԫ��
	c.push_back(10);
// 8. ɾ�����һ��Ԫ��
	c.pop_back();
// 9. ������
	vector<int>:: iterator i = c.begin();	// ����vector��һ��Ԫ�صĵ�����
	vector<int>:: iterator j = c.end();		// ����vector���һ��Ԫ�ص���һ���ĵ�����
// 10. �������
	int s = c[1];
// 11. �Ƚ����㣨�ֵ���
	vector<int> f(4, 3), g(3, 4);
	cout << ((f < g) ? "Yes" : "No") << endl;
// 12. ����vector
	vector<int> v;
	for (int i = 0 ; i < 10 ; ++i)
		v.push_back(i);
	// �� �������
	for (int i = 0 ; i < v.size() ; ++i)
		cout << v[i] << " ";
	cout << endl;
	// �� ������
	for (vector<int>::iterator i = v.begin() ; i != v.end() ; ++i)
		cout << *i << " ";
	cout << endl;
	// �� auto
	for (auto x : v)
		cout << x << " ";
	cout << endl;
	return 0;
}
