#include<iostream>
using namespace std;
int main()
{
	int n,a[101],m,z;
	cin>>n;
	for (int i=0;i<n;i++)  cin>>a[i];
	cin>>m;
	for(int i= 0;i<m;i++)
	{
		cin>>z;
		int left= 0 ,right = n-1,mid;
		for (int j=0; j<n;j++)
		{
			mid = (left+right)/2;
			if(z == a[mid])
			{
				cout<<z<<endl;
				break;
			}
			else if(z>a[mid]) left = mid+1;
			else if(z< a[mid]) right = mid-1;
		}
	}
	return 0;
	
}

