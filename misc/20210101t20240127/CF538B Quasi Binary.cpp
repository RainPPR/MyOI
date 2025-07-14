#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int M = 10;

int ans;
int num[M];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	while (n)
	{
		int add = 0;
		int now = 1;

		int temp = n;
		while (temp)
		{
			if (temp % 10)
				add = add + now;
			now *= 10;
			temp /= 10;
		}

		n -= add;
		num[ans++] = add;
	}

	cout << ans << endl;
	for (int i = 0 ; i < ans ; ++i)
		cout << num[i] << " ";

	return 0;
}
