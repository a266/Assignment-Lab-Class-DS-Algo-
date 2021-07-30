
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 10
#define INF 999

int G[MAX][MAX], n;

void dijk_algo(int G[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], dist[MAX], vis[MAX], pred[MAX];
    int count, min_dist, next_node;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 0)
            {
                cost[i][j] = INF;
            }
            else
            {
                cost[i][j] = G[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        vis[i] = 0;
    }

    dist[start] = 0;
    vis[start] = 1;
    count = 1;

    while (count < n - 1)
    {
        min_dist = INF;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] < min_dist && !vis[i])
            {
                min_dist = dist[i];
                next_node = i;
            }
        }
        vis[next_node] = 1;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                if ((min_dist + cost[next_node][i]) < dist[i])
                {
                    dist[i] = min_dist + cost[next_node][i];
                    pred[i] = next_node;
                }
            }
        }
        count++;
    }
    for(int i = 0; i < n; i++){
        if(i != start){
            cout << "The distance of node " << i << " is " << dist[i] << endl;
            cout << "The path is " << i;

            int j = i;
            do{
                j = pred[j];
                cout << " <- " << j;
            }while(j != start);
        }
        cout << endl;
    }
    int i = n-1;
    if(i != start){
            cout << "The cost of the path is " << dist[i] << endl;
        }
}

int main()
{
    fstream infile;
    infile.open("graphinput.txt", ios::in);

    if (!infile)
    {
        cout << endl
             << "Error to open the file"
             << endl;
        exit(1);
    }

    infile >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            infile >> G[i][j];
        }
    }
    int start;
    cout<<"The Input Graph is: "<<endl;
	for(int i=0 ; i<n ; ++i)
	{
		for(int j=0 ; j<n ; ++j)
		{
			cout<<G[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
    
    cout << "Enter the starting value" << endl;
    cin >> start;

    dijk_algo(G, n, start);
    return 0;
}
