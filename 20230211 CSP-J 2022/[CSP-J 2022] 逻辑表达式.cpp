#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int ansAnd, ansOr;
string str;

bool calc(int l, int r)
{
	int i, j;
	stack<bool> num;
	stack<char> op;
	for (i = l ; i <= r ; ++i)
	{
		// 0 1
		if (str[i] == '0' || str[i] == '1')
		{
			num.push(str[i] - '0');
		}
		// ( )
		else if (str[i] == '(')
		{
			int lk = 1, rk = 0;
			for (j = i + 1 ; j <= r ; ++j)
			{
				if (str[j] == '(')
					++lk;
				else if (str[j] == ')')
					++rk;
				if (rk == lk)
					break;
			}
			num.push(calc(i + 1, j - 1));
			i = j;
		}
		// | &
		else
		{
			op.push(str[i]);
			if (op.size() >= 1)
			{
				bool s = num.top();
				char c = op.top();
				if ((c == '|' && s == 1) || (c == '&' && s == 0))
				{
					num.pop();
					op.pop();
					int lk = 0, rk = 0;
					for (j = i + 1 ; j <= r ; ++j)
					{
						if (str[j] == '(')
							++lk;
						else if (str[j] == ')')
							++rk;
						if (rk == lk && str[j] == '|')
							break;
					}
					i = j - 1;
					if (c == '|' && s == 1)
					{
						++ansOr;
						num.push(1);
					}
					else if (c == '&' && s == 0)
					{
						++ansAnd;
						num.push(0);
					}
				}
			}
		}
		// calc
		if (op.size() && num.size() == op.size() + 1)
		{
			char c = op.top();
			op.pop();
			bool st1 = num.top();
			num.pop();
			bool st2 = num.top();
			num.pop();
			if (c == '|')
				num.push(st1 || st2);
			else
				num.push(st1 && st2);
		}
	}

	return num.top();
}

int main()
{
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);

	ios::sync_with_stdio(false);
	string tstr;
	cin >> tstr;
	for (int i = 0 ; i < tstr.size() ; ++i)
	{
		if ((tstr[i] == '0' || tstr[i] == '1') && (tstr[i + 1] == '&') && (tstr[i + 2] == '0' || tstr[i + 2] == '1'))
			str += "(";
		str += tstr[i];
		if ((tstr[i - 2] == '0' || tstr[i - 2] == '1') && (tstr[i - 1] == '&') && (tstr[i] == '0' || tstr[i] == '1'))
			str += ")";
	}

	printf("%d\n", calc(0, str.size() - 1));
	printf("%d %d\n", ansAnd, ansOr);

	fclose(stdin);
	fclose(stdout);
	return 0;
}
