#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100005;
int l, f[N][2], cnt, top;
char s[N];
string st;
int main()
{
	cin >> l >> st;
	st = '(' + st + ')';
	for(int i = 0; i < l+2; i++)
	{
		if(st[i] == '(')
			s[++top] = st[i];
		if((st[i] == '*' || st[i] == '+') && st[i-1] == '(')
		{
			cnt++;
			f[cnt][0] = f[cnt][1] = 1; //放入新数字 
		}
		if(st[i] == '+')
		{
			while(top > 0 && s[top] == '*') //消除顶部的 * 
			{
				cnt--; top--;
				int a = f[cnt][0], b = f[cnt][1], c = f[cnt+1][0], d = f[cnt+1][1];
				f[cnt][0] = (a * c + a * d + b * c) % 10007;
				f[cnt][1] = b * d % 10007;
			}
			s[++top] = st[i];
		}
		if(st[i] == '*')
		{
			while(top > 0 && s[top] == '*') //消除顶部的 * 
			{
				cnt--; top--;
				int a = f[cnt][0], b = f[cnt][1], c = f[cnt+1][0], d = f[cnt+1][1];
				f[cnt][0] = (a * c + a * d + b * c) % 10007;
				f[cnt][1] = b * d % 10007;
			}
			s[++top] = st[i];
		}
		if(st[i] == ')')
		{
			while(s[top] != '(') // 消除 ( 前的所有字符 
			{
				if(s[top] == '*')
				{
					cnt--; top--;
					int a = f[cnt][0], b = f[cnt][1], c = f[cnt+1][0], d = f[cnt+1][1];
					f[cnt][0] = (a * c + a * d + b * c) % 10007;
					f[cnt][1] = b * d % 10007;
				}
				else
				{
					cnt--; top--;
					int a = f[cnt][0], b = f[cnt][1], c = f[cnt+1][0], d = f[cnt+1][1];
					f[cnt][0] = a * c % 10007;
					f[cnt][1] = (a * d + b * c + b * d) % 10007;
				}
			}
			top--; // 消除 ( 
		}
		if((st[i] == '+' || st[i] == '*') && st[i+1] != '(')
		{
			cnt++;
			f[cnt][0] = f[cnt][1] = 1; //放入新数字 
		}
	}
	printf("%d\n", f[1][0]); // 输出最后结果是 0 的方案数 
	return 0;
}
