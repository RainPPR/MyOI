#include <iostream>

int main()
{
	int in[4];
	for (int i = 0 ; i < 4 ; ++i)
		scanf("%d", in + i);

	int out = ((in[0] ^ in[1]) & (in[2] | in[3])) ^ ((in[1] & in[2]) | (in[0] ^ in[3]));

	printf("%d\n", out);
	return 0;
}
