#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int size1[N];

void make(int v)
{
    parent[v]=-1;
    size1[v]=1;
}


int findSet(int i)
{
    if(parent[i]==-1)
        return i;
    
    return findSet(parent[i]);
}

void unionSet(int u,int v)
{
    int s1=findSet(u);
    int s2=findSet(v);
    if(s1!=s2)
    {
        if(size1[s1]<size1[s2])
            swap(s1,s2);
        parent[s2]=s1;
        size1[s1]+=size1[s2];
    }
}


int main()
{
    system("cls");
    int n,m; //n is nodes,m is edges
    cin>>n>>m;
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,{u,v}});
    }
    
    sort(edges.begin(),edges.end());
    for(int i=0;i<n;i++)
    {
        make(i);
    }
    int tc=0;//tc is total cost
    cout<<"\nMST:"<<endl;
    
    for(auto &edge: edges)
    {
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;
        
        if(findSet(u)==findSet(v))
            continue;
        
        unionSet(u,v);
        tc+=wt;
        cout<<u<<" "<<v<<endl;
    }
    cout<<"\nTotal Cost: "<<tc<<endl;
    return 0;
}