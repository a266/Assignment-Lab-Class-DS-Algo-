#include <iostream>
using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}
     
int maxnumber(int array[], int n)
    {
        if(n == 1)
        	return array[0];
        return max(array[n-1],maxnumber(array,n-1));
    }
    

     
     
int main()
    {
        int n, x;
        cout<<"Enter size of the array: ";
        cin>>n;
        int a[n];
        cout<<"Enter " <<n <<" elements in array: ";
        for(int i=0; i<n; i++)
        {
           cin>>a[i];
        }
     
        x = maxnumber(a, n);
     
        cout<<"Maximum element in array: "<<x<<endl;
     
        return 0;
    }
