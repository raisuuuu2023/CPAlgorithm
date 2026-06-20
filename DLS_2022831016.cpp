#include<iostream>
#include<vector>
using namespace std;
bool DLS(int node,int goal,int limit,vector<vector<int>>&graph,vector<bool>&visited)
{
     if(node==goal) return true;
     if(limit==0) return false;
     visited[node]=true;
     for(int next:graph[node])
     {
        if(!visited[next])
        if(DLS(next,goal,limit-1,graph,visited))
        return true;
     }
     return false;
}
int main()
{
    int n,m;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>m;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int start,goal,limit;
    cin>>start>>goal>>limit;
    vector<bool>visited(n,false);
    if(DLS(start,goal,limit,graph,visited))
       cout<<"Goal found\n";
    else
       cout<<"Goal not found\n";
    
    return 0;
}