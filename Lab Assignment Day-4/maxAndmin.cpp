#include<bits/stdc++.h>
using namespace std;
int maxx, minn;

void maxAndmin(int arr[], int low, int high)
{
 	int max1, min1, mid;
 	if(low==high)
 	{
 	 	maxx = arr[low];
 	 	minn = arr[low];
 	}
 	else
 	{
  		if(low == high-1)
  		{
   			if(arr[low] <arr[high])
   			{
    			maxx = arr[high];
    			minn = arr[low];
   			}
   		else
   		{
    		maxx = arr[low];
    		minn = arr[high];
   		}
  	}
  		else
  		{
   			mid = (low+high)/2;
   			maxAndmin(arr, low, mid);
   			max1 = maxx; min1 = minn;
   			maxAndmin(arr, mid+1, high);
   			if(maxx <max1)
    			maxx = max1;
   			if(minn > min1)
    			minn = min1;
  		}
 	}
}


int main ()
{
 	int n;
 	cout<<"\nEnter the limit of the array : ";
 	cin>>n;
 	int arr[n];
 	cout<<"Enter the Array Elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

 	maxx = arr[0];
 	minn = arr[0];
 	maxAndmin(arr, 0, n-1);
 	cout<<"The maximum element of the array is: "<<maxx<<endl;
	cout<<"The minimum element of the array is: "<<minn<<endl;
 	return 0;
}
