#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;
const double WAITING_RATE = 0.3; // ÿ�εȴ�ʣ��ʱ��İٷֱ�

double original_seconds; // ��ʱʱ����ԭʼ��
double already_seconds;  // �Ѿ��ȴ������ڣ�

// ����
void input()
{
	// ����ȴ���ʱ�䣨���ӣ�
	double original_minutes;
	printf("�������ʱʱ�����Է��Ӽƣ�: ");
	scanf("%lf", &original_minutes);

	// ����ת��
	original_seconds = original_minutes * 60;
}

// ��ȡ��һ�εȴ���ʱ�䣨�룩
double getNextWait()
{
	// ����ʣ���ʱ��
	double remaining_seconds = original_seconds - already_seconds;

	// ����ȴ���ʱ��
	double wait_seconds = remaining_seconds * WAITING_RATE;

	if (wait_seconds <= 0)
		return 1;
	return ceil(wait_seconds);
}

// �ȴ�ָ��ʱ�䣨�룩
void wait(double wait_seconds)
{
	// ��ת���벢����delay
	clock_t delay = wait_seconds * CLOCKS_PER_SEC;

	// ���浱ǰʱ��
	clock_t start = clock();

	// ��ʼ�ȴ�
	while (clock() - start < delay);
}

// ����
void ring()
{
	Beep(523, 500);
}

int main()
{

	// ����
	input();

	// ��ʼ��ʱ
	int count = 0;
	while (already_seconds < original_seconds)
	{
		// ��ȡ�ȴ���ʱ��
		double wait_seconds = getNextWait();

		// ��ʼ�ȴ�
		wait(wait_seconds);

		// һ�μ�ʱ��������
		printf("�����%d\n", ++count);
		ring();

		// ���ϵȴ���ʱ��
		already_seconds += wait_seconds + 0.5;
	}

	// ��ʱ����
	printf("��ʱ����");

	// ��������
	wait(0.5);
	Beep(659, 1000);
	return 0;
}
