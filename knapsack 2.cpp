#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
long long dp[105][1000005];
long long knapsack(int idx,int value,vector<int>&wt,vector<int>&val)
{
    if(value==0) return 0;
    if(idx<0) return 1e15;
    if(dp[idx][value]!=-1) return dp[idx][value];
    long long ans=knapsack(idx-1,value,wt,val);
    if(value-val[idx]>=0)
    {
        ans=min(ans,knapsack(idx-1,value-val[idx],wt,val)+wt[idx]);
    }
    return dp[idx][value]=ans;
}
int main()
{
    int n;
    int w;
    cin>>n>>w;
    vector<int>wt(n),val(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++) cin>>wt[i]>>val[i];
    int max_val=1e5;
    for(int i=max_val;i>=0;i--)
    {
        if(knapsack(n-1,i,wt,val)<=w)
        {
            cout<<i<<"\n";
            break;
        }
    }
    return 0;
}