#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> BIT;
BIT add(BIT &A, BIT &B)
{
	BIT C;
	//��һλ�Ľ�λ
	int t = 0;
	for (int i = 0 ; i < A.size() || i < B.size() ; ++i)
	{
		//��ͬλ�ϵ������
		if (i < A.size())
			t += A[i];
		if (i < B.size())
			t += B[i];
		//����10������һλ��λ
		C.push_back(t % 10);
		t /= 10;
	}
	if (t != 0)
		C.push_back(t);
	return C;
}
int main()
{
	//����
	string a, b;
	cin >> a >> b;
	BIT A, B;
	for (int i = a.size() - 1 ; i >= 0 ; --i)
		A.push_back(a[i] - '0');
	for (int i = b.size() - 1 ; i >= 0 ; --i)
		B.push_back(b[i] - '0');
	//�ӷ�
	BIT C = add(A, B);
	//���
	for (int i = C.size() - 1 ; i >= 0 ; --i)
		printf("%d", C[i]);
	return 0;
}
