#include <bitset>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	// 1 λռ��һ�� bit
	bitset<10000000> b;

	// b.set(pos, value): �ѵ� pos λ�޸�Ϊ value
	b.set(1, 1);
	
	// b.test(pos): ���ص� pos λ��ֵ
	cout << b.test(0) << endl;
	cout << b.test(1) << endl;
	return 0;
}
