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
        {
            if(DLS(next,goal,limit-1,graph,visited))
            return true;
        }
    }
    return false;
}
bool IDS(int start,int goal,vector<vector<int>>&graph)
{
    int maxdepth=graph.size();
    for(int depth=0;depth<=maxdepth;depth++)
    {
        vector<bool>visited(graph.size(),false);
        if(DLS(start,goal,depth,graph,visited))
        {
            cout<<"Goal found at depth "<<depth<<"\n";
            return true;
        }
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
    int start,goal;
    cin>>start>>goal;
    if(!IDS(start,goal,graph))
    {
        cout<<"Goal not found\n";
    }
    return 0;
}