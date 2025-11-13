#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[110][100010];
long long knapsack(int idx,int w,vector<int>&weight,vector<long long>&val)
{
    if(w==0) return 0;
    if(idx<0) return 0;
    if(dp[idx][w]!=-1) return dp[idx][w];
    long long ans=knapsack(idx-1,w,weight,val);
    if(w-weight[idx]>=0)
    {
        ans=max(ans,val[idx]+knapsack(idx-1,w-weight[idx],weight,val));
    }
    return dp[idx][w]=ans;
}
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int>weight(n);
    vector<long long>val(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>weight[i]>>val[i];
    }
    cout<<knapsack(n-1,w,weight,val);
    return 0;
}