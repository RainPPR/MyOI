#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
	unordered_set<int> a, b;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	b.insert(3);
	b.insert(2);
	b.insert(1);
	cout << (a == b) << endl;
	return 0;
}
