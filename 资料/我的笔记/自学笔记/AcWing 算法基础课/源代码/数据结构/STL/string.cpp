#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	// 1. ��ʼ��
	string s1 = "hi";
	string s2("bye");
	// 2. �����ַ�������
	int a = s1.size();
	int b = s2.length();
	// 3. �����ַ����Ƿ�Ϊ��
	bool e = s1.empty();
	// 4. ����ַ���
	s1.clear();
	// 5. �����Ӵ�
	string ss = s2.substr(1, 2);	// ��ʼ�±꣬�Ӵ����ȣ��Ӵ����ȹ����Զ����ԣ�ʡ���Ӵ����ȣ����ش���ʼ�±꿪ʼ���ַ�����β���Ӵ�
	s1.c_str();						// �����ַ��������ַ��������ʼ��ַ
	// 6. ���ַ�����β���
	s2 += ", dog.";
	// 7. ���
	cout << s2 << endl;
	printf("%s\n", s2.c_str());	// c_str() �����ַ��������ַ��������ʼ��ַ
	return 0;
}
