#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> BIT;
//A>=B?
bool cmp(BIT &A, BIT &B)
{
	if (A.size() != B.size())
		return A.size() > B.size();
	for (int i = A.size() - 1 ; i >= 0 ; --i)
		if (A[i] != B[i])
			return A[i] > B[i];
	return 1;
}
//减法 保证A>=B
BIT sub(BIT &A, BIT &B)
{
	BIT C;
	//上一位的借位
	int t = 0;
	for (int i = 0 ; i < A.size(); i++)
	{
		//t = A[i]-B[i]-借位t
		t = A[i] - t;
		if (i < B.size())
			t -= B[i];
		C.push_back((t + 10) % 10);	//(t+10)%10  如果t>=0:等于没加 否则:等于t加10模10
		//如果这一位不够减，向上一位借位
		if (t < 0)
			t = 1;
		else
			t = 0;
	}
	//去掉前导0（如果仅剩一个0，不能去掉）
	while ((C.size() > 1) && (C.back() == 0))
		C.pop_back();
	return C;
}
int main()
{
	//输入
	string a, b;
	cin >> a >> b;
	BIT A, B;
	for (int i = a.size() - 1 ; i >= 0 ; --i)
		A.push_back(a[i] - '0');
	for (int i = b.size() - 1 ; i >= 0 ; --i)
		B.push_back(b[i] - '0');
	//减法
	BIT C;
	if (cmp(A, B))
		C = sub(A, B);
	else
	{
		printf("-");
		C = sub(B, A);
	}
	//输出
	for (int i = C.size() - 1 ; i >= 0 ; --i)
		printf("%d", C[i]);
	return 0;
}
