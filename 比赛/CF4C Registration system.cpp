#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	unordered_map<string, int> id;

	string name;
	while (n--)
	{
		cin >> name;

		if (id[name] == 0)
			cout << "OK\n";
		else
			cout << name << id[name] << "\n";

		++id[name];
	}
	return 0;
}
