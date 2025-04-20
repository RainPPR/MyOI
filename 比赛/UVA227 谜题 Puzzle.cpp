#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct point
{
	int x, y;

	point()
	{
		x = y = 0;
	}
	point(int _x, int _y)
	{
		x = _x, y = _y;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int cnt = 0;
	while (1)
	{
		string a[5];
		getline(cin, a[0]);
		if (a[0] == "Z")
			break;
		getline(cin, a[1]);
		getline(cin, a[2]);
		getline(cin, a[3]);
		getline(cin, a[4]);

		point space;
		for (int i = 0 ; i < 5 ; ++i)
		{
			if (a[i].size() == 4)
			{
				a[i] += "  ";
				space = point(i, 4);
				break;
			}
			bool flag = false;
			for (int j = 0 ; j < 5 ; ++j)
			{
				if (a[i][j] == ' ')
				{
					space = point(i, j);
					flag = true;
					break;
				}
			}
			if (flag)
				break;
		}

		printf("Puzzle #%d:\n", ++cnt);

		string str;
		bool flag = true;
		do
		{
			getline(cin, str);
			for (char op : str)
			{
				switch (op)
				{
					case '0':
					{
						flag = false;
						break;
					}
					case 'A':
					{
						if (space.x == 0)
							goto fail;
						else
						{
							swap(a[space.x][space.y], a[space.x - 1][space.y]);
							--space.x;
							break;
						}
					}
					case 'B':
					{
						if (space.x == 5)
							goto fail;
						else
						{
							swap(a[space.x][space.y], a[space.x + 1][space.y]);
							++space.x;
							break;
						}
					}
					case 'L':
					{
						if (space.y == 0)
							goto fail;

						else
						{
							swap(a[space.x][space.y], a[space.x][space.y - 1]);
							--space.y;
							break;
						}
					}
					case 'R':
					{
						if (space.y == 5)
							goto fail;
						else
						{
							swap(a[space.x][space.y], a[space.x][space.y + 1]);
							++space.y;
							break;
						}
					}
					default:
						;
				}
			}
		} while (flag);

		for (int i = 0 ; i < 5 ; ++i, putchar('\n'))
			for (int j = 0 ; j < 5 ; ++j)
				putchar(a[i][j]), putchar(' ');
		putchar('\n');
		continue;

fail:
		printf("This puzzle has no final configuration.\n\n");
	}

	return 0;
}
