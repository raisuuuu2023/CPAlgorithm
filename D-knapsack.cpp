#include<iostream>
#include<vector>
using namespace std;
long long knapsack(int W,vector<int>&w, vector<long long>& v,int idx,vector<vector<long long>>& memo)
{
    if(idx<0) return 0;
    if(memo[W][idx]!=-1) return memo[W][idx];
    if(w[idx]>W)
    {
        memo[W][idx]=knapsack(W,w,v,idx-1,memo);
    }
    else
    {
        memo[W][idx]=max(v[idx]+knapsack(W-w[idx],w,v,idx-1,memo),knapsack(W,w,v,idx-1,memo));
    }
    return memo[W][idx];
}
int main()
{
    int N,W;
    cin>>N>>W;
    vector<int>w(N);
    vector<long long>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>w[i]>>v[i];
    }
    vector<vector<long long>>memo(W+1,vector<long long>(N,-1));
    long long ans=knapsack(W,w,v,N-1,memo);
    cout<<ans<<"\n";
    return 0;
}