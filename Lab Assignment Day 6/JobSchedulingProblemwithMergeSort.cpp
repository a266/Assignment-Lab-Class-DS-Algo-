#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};

void merge(Job a[] , int l , int mid , int r , int n){
    int i=l , j=mid+1 , k=l ,  t=1;
    Job z[r+1];
    while( i<=mid && j<=r){
        if(a[i].profit>=a[j].profit)
            z[k++]=a[i++];
        else
            z[k++]=a[j++];
        }
    while(i<=mid) z[k++]=a[i++];
    while(j<=r) z[k++]=a[j++];
    
    for(int i=l ; i<=r ; ++i)
        a[i]=z[i];
}
void merge_sort(Job a[] , int l , int r , int n){
    int mid ;
    static int t=1;
    if(l<r){
         mid=(l+r)/2;
        merge_sort(a , l , mid , n);
        merge_sort(a , mid+1 , r , n);
        merge(a , l , mid , r , n);
       

}
}



void JobScheduling(Job arr[], int n) 
    {
        bool done[n]={0};
        int day=0;
        int profit=0;
        for(int i=0;i<n;i++){
            for(int j=min(n,arr[i].dead-1);j>=0;j--){
                if(done[j]==false){
                    day+=1;
                    profit=profit + arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
        cout<<"The maximum profit is: "<<profit<<endl;
        for(int i=0;i<n;i++){
        	if(done[i]==true){
        		cout<<"J"<<i<<" ";
			}
			else{
				continue;
			}
		}
    } 


int main(){
    int n;
    cout<<"Enter the number of element you want to enter: ";
    cin>>n;
    Job arr[n];
    cout<<"Enter deadline, profit sequantially: "<<endl;
    for(int i=0;i<n;i++){
    	cout<<"Job Id: J"<<i<<": ";
//        cin>>arr[i].id;
        cin>>arr[i].dead;
        cin>>arr[i].profit;
        
    }
    merge_sort(arr , 0 , n-1 , n);
    JobScheduling(arr,n);
    return 0;
}
