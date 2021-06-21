#include<iostream>
#include<fstream>
using namespace std;
int graph[100][100];
int graph_res[100][100]={0};
int res_size=0;
int set[100];


int n;
int ans=0;
struct kruskal
{
	char u;
	char v;
	int weight;
};
kruskal  res[100];
void merge(kruskal a[] , int l , int mid , int r , int n){
	int i=l , j=mid+1 , k=l   , t=1;
	kruskal z[r+1];
	while(i<=mid && j<=r){
		if(a[i].weight<=a[j].weight)
			z[k++]=a[i++];
		else
			z[k++]=a[j++];
		}
	while(i<=mid) z[k++]=a[i++];
	while(j<=r) z[k++]=a[j++];
	
	for(int i=l ; i<=r ; ++i)
		a[i]=z[i];
}
void merge_sort(kruskal a[] , int l , int r , int n){
	int mid ;
	
	if(l<r){
		 mid=(l+r)/2;
		merge_sort(a , l , mid , n);
		merge_sort(a , mid+1 , r , n);
		merge(a , l , mid , r , n);
		
	}

}
int find(int i)
{
	while(set[i]>0)
		i=set[i];
	return i;
}
void weighted_union(int i , int j)
{
	int indx1=find(i) , indx2=find(j);
	i=indx1 , j=indx2;
	int temp=set[i]+set[j];
	if(set[i]>set[j])
	{
		set[i]=j;
		set[j]=temp;
	}
	else
	{
		set[j]=i;
		set[i]=temp;
	}
}

void MST_kruskalkal(kruskal a[] , int size)
{
	for(int i=0 ; i<n ; ++i)
		set[i]=-1;
	merge_sort(a , 0 , size-1 , size);
	
	
	int k=0;
	for(int i=0 ; i<size ; ++i)
	{
		if(find(a[i].u-'A')!=find(a[i].v-'A'))
		{
			cout<<a[i].u<<"->"<<a[i].v<<"->"<<a[i].weight<<endl;
			
			ans+=a[i].weight;
			res[res_size].u=a[i].u;
			res[res_size].v=a[i].v;
			res[res_size].weight=a[i].weight;
			++res_size;
			weighted_union(a[i].u-'A' , a[i].v-'A');
		}


	}
}
int main()
{
	fstream infile;
	infile.open("graphinput.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	
	infile>>n;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			infile>>graph[i][j];
		}
	}
	int k=0;
	kruskal graph_pair[100];
	cout<<"The input graph is"<<endl;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}

	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<=i ; ++j)
		{
			if(graph[i][j])
			{
				graph_pair[k].u=i+'A';
				graph_pair[k].v=j+'A';
				graph_pair[k].weight=graph[i][j];
				++k;
			}
		}
	}
	
	
	int size=k;
	MST_kruskalkal(graph_pair , size);
	cout<<"Total weight"<< " "<<ans<<endl;
	for(int i=0 ; i<res_size ; ++i)
	{
		graph_res[res[i].u-'A'][res[i].v-'A']=res[i].weight;

	}
	cout<<"The output graph is"<<endl;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<graph_res[i][j]<<" ";
		}
		cout<<endl;
	}
	

}
