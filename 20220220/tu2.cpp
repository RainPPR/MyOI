#include<iostream>
#include<vector>
using namespace std;
vector<int> d[100];
int main()
{
	int dian = 0,bian = 0;
	cin >> dian >> bian;
	for(int i = 0 ; i < bian ; i++)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;
		d[start].push_back(end);
		d[end].push_back(start);
	}
	cout << "jz: " << endl;
	for(int i = 1 ; i <= dian ; i++)
	{
		cout << i << " -> ";
		for(int j = 0 ; j < d[i].size() ; j++)
		{
			cout << d[i][j] << " , ";
		}
		cout << endl;
	}
	return 0;
}