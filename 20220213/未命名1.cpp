#include<iostream> 
#include<cmath>
using namespace std; 
int main()
{
  int an; 
  int score = 0;
  for(int i=0;i<10;i++)
  { 
      int a = rand()%100+1;
      int b = rand()%100+1;
      cout<<a<<"+"<<b<<"=";
      cin>>an;
      if(a+b == an)
      {
      	cout<<"回答正确，+10分"<<endl;
        score += 10;  
	  }
	  else 
	  {
	  	cout<<"回答错误，不得分"<<endl;
	  }
  }
  cout<<score<<endl;
return 0;
}