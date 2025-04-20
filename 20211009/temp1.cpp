#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;
/*
int gcd(int a,int b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b,a%b);
}
bool zhi1(int n)
{
	for(int i = 2 ; i*i <= n ; i++)
	{
		if(n % i == 0)
		{
			return false;
		}
	}
	return true;
}
bool zhi[100000] = {0};
bool zhi2()
{
	for(int i = 2 ; i <= 100000 ; i++)
	{
		if(zhi[i] == 0)
		{
			for(int j = 2*i ; j <= 100000 ; j+=i)
			{
				zhi[j] = 1;
			}
		}
		zhi[i] = !zhi[i];
	}
}
*/
long long chaishu(long long n) 
{
	bool fu = false;
	if(n < 0) 
	{
		fu = true;
		n = -n;
	}
	long long nn = 0;
	while(n != 0)
	{
		nn = nn*10+n%10;
		n/=10;
	}
	if(fu)
	{
		nn = -nn;
	}
	return nn;
}
double sishewuru(double n,int wei)
{
	n = n*(double)(pow(10,wei));
	n += 0.5;
	n = (int)n;
	n = n/(double)pow(10,wei);
	return n;
}
int main()
{
//	freopen("xxx.in","r",stdin);
//	freopen("xxx.out","w",stdout);

/*
	//ÅÅÐò 
	srand(time(0));
	int n = 0;
	n = rand()%26+5;
	int a[1000] = {0};
	for(int i = 0 ; i < n ; i++)
	{
		a[i] = rand()%1000+100;
	}
	/*
	//Ã°ÅÝ
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = 0 ; j < n-i-1 ; j++)
		{
			if(a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	for(int i = 0 ; i < n ; i++)
	{
		cout << a[i] << endl;
	}
	*/
	/*
	//Í°
	int tong[100000] = {0};
	int maxt = -1;
	for(int i = 0 ; i < n ; i++)
	{
		tong[a[i]]++;
		if(a[i] > maxt)
		{
			maxt = a[i];
		}
	}
	for(int i = 0 ; i <= maxt ; i++)
	{
		for(int j = 1 ; j <= tong[i] ; j++)
		{
			cout << i << endl;
		}
	}
	*/
/*
	//²ðÊý
	long long n = 0;
	cin >> n;
	cout << chaishu(n) << endl;
*/
/*
	//ËÄÉáÎåÈë 
	float n = 0;
	cin >> n;
	int wei = 0;
	cin >> wei;
	cout << sishewuru(n,wei) << endl;
*/
/*
	char str[256] = {0};
	cin.getline(str,256);
	int tong[26] = {0};
	for(int i = 0 ; i < strlen(str) ; i++)
	{
		if((str[i] >= 'a') && (str[i] <= 'z'))
		{
			tong[str[i]-'a']++;
		}
	}
	for(int i = 0 ; i < 26 ; i++)
	{
		cout << (char)('a'+i) << ":" << tong[i] << endl;
	}
*/
	float a = 0,b = 0;
	cin >> a >> b;
	float c = a*100/b;
	printf("%.2f%%",c);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
