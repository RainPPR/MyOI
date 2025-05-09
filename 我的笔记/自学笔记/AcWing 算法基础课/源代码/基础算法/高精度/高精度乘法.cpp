#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> BIT;
BIT mul(BIT &A, int b)
{
	BIT C;
	//上一位的进位
	int t = 0;
	for (int i = 0 ; i < A.size() ; ++i)
	{
		//每一位都乘b
		t += A[i] * b;
		//超过10就向上一位进位
		C.push_back(t % 10);
		t /= 10;
	}
	if (t != 0)
		C.push_back(t);
	while ((C.size() > 1) && (C.back() == 0))
		C.pop_back();
	return C;
}
int main()
{
	//输入
	string a;
	int b = 0;
	cin >> a >> b;
	BIT A;
	for (int i = a.size() - 1 ; i >= 0 ; --i)
		A.push_back(a[i] - '0');
	//乘法
	BIT C = mul(A, b);
	//输出
	for (int i = C.size() - 1 ; i >= 0 ; --i)
		printf("%d", C[i]);
	return 0;
}
