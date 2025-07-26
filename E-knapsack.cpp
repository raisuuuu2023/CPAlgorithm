#include<iostream>
#include<vector>
using namespace std;
long long knapsack(int idx,long long W,vector<long long>& w, vector<int>& v,vector<vector<long long>>& memo)
{
    if(idx<0) return 0;
    if(memo[idx][W]!=-1) return memo[idx][W];
    if(w[idx]>W)
    {
        memo[idx][W]=knapsack(idx-1,W,w,v,memo);
    }
    else
    {
        memo[idx][W]=max(v[idx]+knapsack(idx-1,W-w[idx],w,v,memo),knapsack(idx-1,W,w,v,memo));
    }
    return memo[idx][W];
}
int main()
{
    int N;
    long long W;
    cin>>N>>W;
    if(W>10000) return 1;
    vector<long long>w(N);
    vector<int>v(N);
    for(int i=0;i<N;i++)
    {
        cin>>w[i]>>v[i];
    }
    vector<vector<long long>>memo(N,vector<long long>(W + 1, -1));
    cout<<knapsack(N-1,W,w,v,memo)<<"\n";
    return 0;
}