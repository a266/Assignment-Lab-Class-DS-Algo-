#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};


bool compare(Job a,Job b){
    return a.profit>b.profit;
}

void JobScheduling(Job arr[], int n) 
    {
        sort(arr,arr+n,compare);
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
    } 


int main(){
    int n;
    cout<<"Enter the number of element you want to enter: ";
    cin>>n;
    Job arr[n];
    cout<<"Enter Job Id, profit, deadline sequantially: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i].id;
        cin>>arr[i].profit;
        cin>>arr[i].dead;
    }
    JobScheduling(arr,n);
    return 0;
}