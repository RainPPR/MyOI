#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
	int n;
	string str;
	cin >> n >> str;

	set<char> st;
	for (char i : str)
		if (i < 'a')
			st.insert(i -  'A' + 'a');
		else
			st.insert(i);

	if (st.size() == 26)
		printf("YES");
	else
		printf("NO");
	return 0;
}
