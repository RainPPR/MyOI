/*
  �����������µķ��壬ҡ�ε������ܶ�����
  ˼�����÷���²�ͣ���ҵ��ľ�һƬ��Ţ��
  ɢ���������ķ��ǣ���˸�����ҵ�������
  ����Ҷ��ӯ������ģ�����ɽˮһƬ������

  �������� & ���š������֡�
 */
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int q[N];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0 ; i < n ; ++i)
		scanf("%d", q + i);

	sort(q, q + n);

	int ans = 2e9;
	for (int i = 0 ; i < n - m + 1 ; ++i)
	{
		int c = q[i + m - 1] - q[i];
		ans = (c < ans) ? c : ans;
	}

	printf("%d\n", ans);
	return 0;
}
