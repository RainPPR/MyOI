/*
  ��ʢ��֮ĩ����ҹ�����ȡ�
  ��һ����ϣ���ʼ������
  ���ȵ����㣬����ˮ���ۡ�
  ���ﶼֵ�ã��������ᡣ

  �������١�����Ϊө��
 */
#include <cstdio>

using namespace std;

const int N = 5e5 + 10;

int n;
int x[N], a[N];

// ��� n = 2 ������
namespace Solve1
{
	bool Main()
	{
		// �ݼ�
		if (a[1] > a[2])
			printf("0 %d", x[1]);
		// ����
		else
			printf("%d 0", x[2]);
		return true;
	}
}

// ��� �������������� ������
namespace Solve2
{
	bool Main()
	{
		// Ѱ�ҷ�ֵ
		int max_x = -1, max_a = -1, max_i = 0;
		for (int i = 1 ; i <= n ; ++i)
			if ((max_x == -1) || (a[i] > max_a))
				max_x = x[i], max_a = a[i], max_i = i;
		// ����ֵ��Ϊ 0 �⣬�����Ϊ��ֵ����
		for (int i = 1 ; i < max_i ; ++i)
			printf("%d ", max_x);
		printf("0 ");
		for (int i = max_i + 1 ; i < n ; ++i)
			printf("%d ", max_x);
		printf("%d", max_x);
		return true;
	}
}

// ����ģ��
namespace Solve3
{
	// ������ʱ���ꣻʣ��ө����������Ƿ����
	int xt[N], cnt;
	// ����ÿһ��ө��棬������ڵ�ө������ꡢ�Ҳ����ڵ�ө�������
	int le[N], rt[N];
	// ����ÿһ��ө����Ƿ����
	bool is[N];
	// �����
	int ans[N];
	// ��ʼ��
	bool init()
	{
		cnt = n;
		for (int i = 1 ; i <= n ; ++i)
			le[i] = i - 1, rt[i] = i + 1, is[i] = true, xt[i] = ::x[i];
		return true;
	}

	bool Main()
	{
		// ��ʼ������
		init();
		// �ظ�����ֱ����ʣһ��ө���
		while (cnt > 1)
		{
			// ö��ÿһֻө��棬�ж�Ӧ�����Ǹ������ߣ���������ʱ����������
			for (int i = 1 ; i <= n ; ++i)
			{
				if (is[i])
				{
					int l = le[i], r = rt[i];
					// ���������ߣ��Ҳ��������
					int s = (a[l] > a[r]) ? -1 : 1;	// �����������
					int p = (a[l] > a[r]) ? l : r;	// ��߻��ұߵ�ө����±�
					if (a[i] < a[p])
					{
						xt[i] = x[i] + s;
						// ������������� a ��С����ʧ������������ө�����ҡ������꣩
						if (xt[i] == x[p])
						{
							int tl = le[i], tr = rt[i];
							rt[tl] = tr, le[tr] = tl;
							ans[i] = xt[i];
							is[i] = false;
							--cnt;
						}
					}
				}
			}
			// �������ݣ�����ʱ��������ݸ��Ƶ�������
			for (int i = 1 ; i <= n ; ++i)
				x[i] = xt[i];
		}
		for (int i = 1 ; i < n ; ++i)
			printf("%d ", ans[i]);
		printf("%d", ans[n]);
		return true;
	}
}

int main()
{
	// �жϵ���������������
	int isTwo = 0;
	// ����
	scanf("%d", &n);
	x[0] = -2e9;
	x[n + 1] = 2e9;
	a[0] = a[n + 1] = -2e9;
	for (int i = 1 ; i <= n ; ++i)
		scanf("%d", x + i);
	for (int i = 1 ; i <= n ; ++i)
	{
		scanf("%d", a + i);
		if ((isTwo == 0 && a[i] < a[i - 1]) || (isTwo == 1 && a[i] > a[i - 1]))
			++isTwo;
	}

	// �������
	if (n == 2)
		Solve1::Main();
	//else if (isTwo != 2)
	//	Solve2::Main();
	else
		Solve3::Main();
	return 0;
}
