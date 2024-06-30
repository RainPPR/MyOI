#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> BIT;
BIT mul(BIT &A, int b)
{
	BIT C;
	//��һλ�Ľ�λ
	int t = 0;
	for (int i = 0 ; i < A.size() ; ++i)
	{
		//ÿһλ����b
		t += A[i] * b;
		//����10������һλ��λ
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
	//����
	string a;
	int b = 0;
	cin >> a >> b;
	BIT A;
	for (int i = a.size() - 1 ; i >= 0 ; --i)
		A.push_back(a[i] - '0');
	//�˷�
	BIT C = mul(A, b);
	//���
	for (int i = C.size() - 1 ; i >= 0 ; --i)
		printf("%d", C[i]);
	return 0;
}
