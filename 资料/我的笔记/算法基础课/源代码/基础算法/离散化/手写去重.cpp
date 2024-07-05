#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>::iterator unique(vector<int> &a)
{
	sort(a.begin(), a.end());
	int j = 0;
	for (int i = 0 ; i < a.size() ; ++i)
		if (!i || a[i] != a[i - 1])
			a[j++] = a[i];
	return a.begin() + j;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0 ; i < n ; ++i)
	{
		int x = 0;
		scanf("%d", &x);
		a.push_back(x);
	}
	auto b = unique(a);
	for (auto i = a.begin() ; i != b ; i++)
	{
		printf("%d ", *i);
	}
	return 0;
}
