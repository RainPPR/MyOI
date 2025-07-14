#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	int n, m;
	while (T--)
	{
		scanf("%d %d", &n, &m);

		int ans = 0;

        cout << "! " << endl;
        cout << ((n - 1) / 2) * ((m - 1) / 2) << endl;
        cout << (((n + 1) / 2) * ((m + 1) / 2) - (n % 2) - (m % 2) - (m % 2) * (n % 2) - 1) << endl;
        cout << ((n % 2) + (m % 2) + (m % 2) * (n % 2) + 1) << endl;
        
		ans += ((n - 1) / 2) * ((m - 1) / 2) * 4;
		ans += ((n % 2) + (m % 2) + (m % 2) * (n % 2) + 1) * 2;
		ans += (((n + 1) / 2) * ((m + 1) / 2) - (n - 1) / 2) * ((m - 1) / 2 - (n % 2) - (m % 2) - (m % 2) * (n % 2) - 1) * 3;

		printf("%d\n", ans);
	}

	return 0;
}
