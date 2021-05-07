#include<iostream>
#include <fstream>
#include<string>
using namespace std;

int main () {
	fstream infile; //create aa object of fstream class
	infile.open("fileex.txt", ios::in); //open a file in read mode


	if (!infile) { //to check whether the file is opened
	cout<<"\nError to open the file\n"<<endl;
	exit (1);
	}
	int n;
	infile>>n; //to read number of vertices from file
	int mat[10][10];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			infile>>mat[i][j]; //read a graph from file
		}
	}
	
	int e=0;
    for(int i =0 ; i<n ; ++i)
    {
        for(int j=0 ; j<n ; ++j)
            if(mat[i][j]) ++e;
    }
	cout<< "Tolal no. of edges "<<e/2<<endl;
    cout<< "Tolal no. of degree "<<e<<endl;
	
	int v;
    cout<<" Enter the vertex" <<endl;
    cin>>v;

    for(int i=0 ; i<n ; ++i)
    {
        if(mat[v][i]) cout<<i<<" ";
    }
	
	cout<<endl;
     cout<< "The graph is"<<endl;
     for(int i =0 ; i<n ; ++i)
     {
           cout<<i<<"-->";
           for(int j=0 ; j<n ; ++j)
            {
                  if(mat[i][j]) cout<<j<<"-->";
            }
            cout<<endl;
     }
	
//	
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			cout<<mat[i][j]; //read a graph from file
//		}
//	cout<<endl;
//	}
//	infile.close (); //to close the file
	return 0;
}
