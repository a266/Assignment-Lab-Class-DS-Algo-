#include <iostream>
using namespace std;

int sumOfDigit(int num) {

   if (num <= 0) {
  
     return 0;
  
   } 
 
   return ( num % 10) + sumOfDigit( num / 10);
}

int main() {
 
  int n, x;
 
  cout<<"Enter a number: ";
  cin>>n;
 
  x = sumOfDigit(n);
 
  cout<<"The sum of digit is: "<<x<<endl;
 
  return 0;
}
