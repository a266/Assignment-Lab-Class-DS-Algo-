#include<iostream>
using namespace std;

int rev(int n,int temp)
{ 
	if(n==0)
		return temp;
	temp=(temp*10)+(n%10);
  	
	return rev(n/10,temp);
}

int main()
{
   	int n;
   	cout<<"Enter number to check pallindrome:";
   	cin>>n;
   	int x = rev(n,0);
   	if(x==n)
   		cout<<"yes, it is pallindrome"<<endl;
   	else
   		cout<<"no it is not pallindrome"<<endl;
  	return 0;
}

