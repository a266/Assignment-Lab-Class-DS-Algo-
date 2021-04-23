#include<iostream>
using namespace std;

int gcd(int n1,int n2)
{
	if (n2 == 0)
   		return n1;
   	return gcd(n2, n1 % n2);
}

int main()
{
	int n1,n2;
	cout<<"Enter two numbers: ";
	cin>>n1;
	cin>>n2;
	int x;
	x=gcd(n1,n2);
	cout<<"The gcd is: "<<x<<endl;
	return 0;	
}
