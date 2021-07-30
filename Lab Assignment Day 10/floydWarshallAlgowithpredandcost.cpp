#include<bits/stdc++.h>
#include<fstream>
using namespace std;

int graph[1000][1000];
int V;
int dist[1000][1000];
int pred[1000][1000];
int ca=1;

void shortest_path(int i , int j)
{
	if(i==j)
	{
		cout<<char(i+65)<<" ";
		return;
	}
	if(pred[i][j]==-1)
	{
		cout<<"No shortest path is found"<<endl;
		return;
	}
	else
	{
		
		shortest_path(i , pred[i][j]);
		cout<<char(j+65)<<" ";
		
	}
}




void floyd_warshall()
{
	
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			pred[i][j]=-1;
			dist[i][j]=INT_MAX;
		}
	}
	

	for(int i=0;i<V;++i)
		for(int j=0;j<V;++j){
			dist[i][j] = graph[i][j];
			if(graph[i][j]==0 or graph[i][j]==INT_MAX)
				pred[i][j]=-1;
			else pred[i][j]=i;
		}
			


	for(int k=0;k<V;++k){
		for(int i=0;i<V;++i){
			for(int j=0;j<V;++j){
			if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					pred[i][j]=pred[k][j];
				}
			}
		}
		
		cout<<endl<<endl;
		
	cout<<"D-"<<ca<<endl<<endl;		
	cout<<"The Cost Table is: "<<endl;
	for(int i=0 ; i<V ; ++i)
      	{
     			for(int j=0 ; j<V ; ++j)
     			{
     				if(dist[i][j]==999)
     					cout<<"INF"<<"\t";
     				else cout<<dist[i][j]<<"\t";
     			}
     			cout<<endl;
      	}
		cout<<endl<<endl;  
		
	cout<<"The Predecessor Table is: "<<endl;
	for(int i=0 ; i<V ; ++i)
      	{
     			for(int j=0 ; j<V ; ++j)
     			{
     				if(dist[i][j]==999)
     					cout<<"INF"<<"\t";
     				else cout<<pred[i][j]<<"\t";
     			}
     			cout<<endl;
      	}
		cout<<endl<<endl; 
		
	ca++;
		
	}
	cout<<"The Shortest Paths are: "<<endl;
	cout<<"-----------------------------"<<endl;
	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			cout<<char(i+65)<<"  "<<char(j+65)<<"  "<<dist[i][j]<<endl;
			shortest_path(i,j);
			cout<<endl<<endl;
		}
		cout<<"------------------------------"<<endl;
	}
}



int main()
{
	fstream infile;
	infile.open("inputGraph.txt" , ios::in);
	if(!infile)
	{
		cout<<"Error on openning file"<<endl;
		return 0;
	}
	
	infile>>V;
	


	for(int i=0;i<V;i++){
		for(int j=0;j<V;j++){
			infile>>graph[i][j];
		}
	}


	cout<<"The input graph is"<<endl;
	for(int i=0 ; i<V ; ++i)
	{
		for(int j=0 ; j<V ; ++j)
		{
			cout<<graph[i][j]<<"\t";
		}
		cout<<endl;
	}
	int E=0;

	floyd_warshall();
	
	return 0;
}


