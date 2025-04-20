#include <iostream>
#include <cstring>

using namespace std;

string itos(int n)
{
	if (n == 0)
		return "0";
	string ans;
	while (n)
		ans = char(n % 10 + '0') + ans, n /= 10;
	return ans;
}

int main()
{
	string a, b;

	cin >> a >> b;

	int t, cmax = -1;
	for (int i = 0 ; i < a.size() ; ++i)
	{
		t = a[i] - '0';
		cmax = (t > cmax) ? t : cmax;
	}
	for (int i = 0 ; i < b.size() ; ++i)
	{
		t = b[i] - '0';
		cmax = (t > cmax) ? t : cmax;
	}

	++cmax;

	while (a.size() < b.size())
		a = "0" + a;
	while (b.size() < a.size())
		b = "0" + b;
	a = "0" + a, b = "0" + b;

	string ans;
	int left = 0;
	for (int i = a.size() - 1 ; i >= 0 ; --i)
	{
		int now = int(a[i] - '0') + int(b[i] - '0') + left;
		left = 0;

		if (now >= cmax)
			left += now / cmax, now -= cmax;

		ans = itos(now) + ans;
	}

	int len = ans.size();
	for (int i = 0 ; ans[i] == '0' ; ++i)
		--len;

	cout << len << endl;
	return 0;
}
