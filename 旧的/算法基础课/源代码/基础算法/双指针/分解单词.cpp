#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
char str[1010];
int main()
{
	cin.getline(str, sizeof(str));
	int n = strlen(str);
	for (int i = 0; i < n; ++i)
	{
		int j = i;
		while (j < n && str[j] != ' ')
			j++;
		for (int k = i ; k < j; ++k)
			printf("%c", str[k]);
		printf("\n");
		i = j;
	}
	return 0;
}
