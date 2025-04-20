#include<iostream>
#include<cmath>
using namespace std;
bool issu(int n)
{
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i == 0)  ruturn false;

		
	}
	return true;
	
}
int main()
{
	int a;
	cin>>n;
	if(issu(n))  cout<<"su";
	else cout<<"no"<<endl;
	ruturn 0;
}
