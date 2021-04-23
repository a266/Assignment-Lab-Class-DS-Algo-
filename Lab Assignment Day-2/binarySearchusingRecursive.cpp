#include <iostream>
using namespace std;

int BinarySearch(int arr[], int num, int beg, int end)
{
 	int mid;
 	if (beg > end){
  
  	cout << "Number is not found";
  	return 0;
  
 	}
	else
	{
  		mid = (beg + end) / 2; 
  		if(arr[mid] == num){
   
   	cout << "Number is found at " << mid << " index \n";
   	return 0;
  
  	} 
	else if (num > arr[mid]) {
   		BinarySearch (arr, num, mid+1, end);
  	}
	else if (num < arr[mid]) {
   		BinarySearch (arr, num, beg , mid-1);
  	}
 	}
}
 
int main() {
 
 	int n, beg, end;
 	cout <<"Enter the size of an array \n";
 		cin >> n;
 	int a[n];
 	cout <<"Enter the sorted Elements \n";
 
 	for(int i=0; i<n; i++) {
  	cin >> a[i];
 	}
 	int num;
 	cout <<"Enter a value to be search \n";
 	cin >> num;
 
 	beg = 0;
 	end = n-1;
 	BinarySearch (a, num, beg, end);
 
 	return 0;
}
