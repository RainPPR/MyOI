#include<iostream>
#include<cmath>
using namespace std;
bool issu(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n % i == 0)  return false;

		
	}
	return true;
	
}
int main()
{
	int m,n,a[100001],l=0,b[100001];
	cin>>m>>n;
	for(int i=m;i<=n;i++)
	{
		if(issu(1))
		{
			a[l] = i;
			l++;
		}  
	}
	
	for(int i = 0;i<1;i++)
	{
		int k =0;n
		int temp = a[i];
		while(temp>0)
		{
			k*=10;
			k+=temp%10;
			temp/=10; 
		}
		b[i] = k;
		cout<<b[i]<<" ";
		
	}
	for(int i=0;i<l;i++)
	{
		if(issu(a[i])  && issu (b[i]))
		{
			cout<<a[i]<<" ";
		}
	}
	
	return 0;
}

