#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N=500;
const int I=1e9+10;
int dist[N][N];

int main()
{
    system("cls");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(i==j) 
                dist[i][j]=0;
            else 
                dist[i][j]=I;
        }
    }
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
    
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]>=I)
                cout<<"I ";
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    // int a,b;
    // cout<<"Enter node u and v to find shortest distance between them: "<<endl;
    // cin>>a>>b;
    // if(dist[a][b]==I)
        // cout<<"Infinity"<<endl;
    // else
    //     cout<<"Shortest distance between node "<<a<<" and "<<b<<": "<<dist[a][b]<<endl;
    return 0;
}