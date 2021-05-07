#include<iostream>
using namespace std;
int count=0;
int pass=0;

void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
   	int k = left;
    int z[100];
 
    while (i <= mid && j <= right && (++count)) {
        if (arr[i] <= arr[j]) {
            z[k++] = arr[i++];
        }
        else {
            z[k++] = arr[j++];
        }
	}
    while (i <= mid) {
        z[k++] = arr[i++];
    }
    while (j <= right) {
        z[k++] = arr[j++];
    }
    for(int i=left;i<=right;i++)
    	arr[i]=z[i];
}


void mergeSort(int arr[],int l,int r)
{
    if(l<r)
	{
        int m = (l+r-1)/2;
    	mergeSort(arr,l,m);
    	mergeSort(arr,m+1,r);
    	merge(arr,l,m,r);
    	cout<<endl<<"Pass: "<<++pass<<endl;
    	for (int i = l; i <= r; i++)
    	{
    		cout << arr[i] << " ";
		}
        cout << endl;
    }
    
}


void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}


int main()
{
	int n;
	cout<<"Enter the array limit: ";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

    mergeSort(arr,0,n-1);
    cout<<endl;
	cout<<"Sorted Array:"<<endl;
    printArray(arr,n);
    cout<<endl<<endl;
    cout<<"The number of comparision is: "<<count<<endl;
    return 0;
}
