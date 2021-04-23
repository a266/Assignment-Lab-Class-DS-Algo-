#include<iostream>
using namespace std;
int c;

void towers(int n,char frompeg,char topeg,char auxpeg)
{
	if(n==1){
		cout<<"move disk 1 from peg "<<frompeg<<" to peg "<<topeg<<endl;
		c++;
		return;
	}
	towers(n-1,frompeg,auxpeg,topeg);
	cout<<"move disk "<<n<<" from peg "<<frompeg<<" to peg "<<topeg<<endl;
	towers(n-1,auxpeg,topeg,frompeg);
	c++;
}


int main()
{
	int n;
	cout<<"Enter number of disk: "<<endl;
	cin>>n;
	towers(n,'A','C','B');
	cout<<"Number of steps: "<<c<<endl;
	return 0;
}
