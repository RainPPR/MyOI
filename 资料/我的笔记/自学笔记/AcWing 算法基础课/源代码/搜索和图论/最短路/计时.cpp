#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;
const double WAITING_RATE = 0.3; // 每次等待剩余时间的百分比

double original_seconds; // 计时时长（原始）
double already_seconds;  // 已经等待（现在）

// 输入
void input()
{
	// 输入等待的时间（分钟）
	double original_minutes;
	printf("请输入计时时长（以分钟计）: ");
	scanf("%lf", &original_minutes);

	// 分钟转秒
	original_seconds = original_minutes * 60;
}

// 获取下一次等待的时间（秒）
double getNextWait()
{
	// 计算剩余的时间
	double remaining_seconds = original_seconds - already_seconds;

	// 计算等待的时间
	double wait_seconds = remaining_seconds * WAITING_RATE;

	if (wait_seconds <= 0)
		return 1;
	return ceil(wait_seconds);
}

// 等待指定时间（秒）
void wait(double wait_seconds)
{
	// 秒转毫秒并存入delay
	clock_t delay = wait_seconds * CLOCKS_PER_SEC;

	// 储存当前时间
	clock_t start = clock();

	// 开始等待
	while (clock() - start < delay);
}

// 响铃
void ring()
{
	Beep(523, 500);
}

int main()
{

	// 输入
	input();

	// 开始计时
	int count = 0;
	while (already_seconds < original_seconds)
	{
		// 获取等待的时间
		double wait_seconds = getNextWait();

		// 开始等待
		wait(wait_seconds);

		// 一次计时结束提醒
		printf("响铃×%d\n", ++count);
		ring();

		// 加上等待的时间
		already_seconds += wait_seconds + 0.5;
	}

	// 计时结束
	printf("计时结束");

	// 结束铃声
	wait(0.5);
	Beep(659, 1000);
	return 0;
}
