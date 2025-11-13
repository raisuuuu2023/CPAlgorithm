#include<iostream>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
const int n=1e5+10;
int dp[n];
int h[n];
int frog2(int i,int k)
{
    int mincost=INT_MAX;
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    for(int j=1;j<=k;j++)
    {
        if(i-j>=0)
        mincost=min(mincost,frog2(i-j,k)+abs(h[i]-h[i-j]));
    }
    return dp[i]=mincost;
}
int main()
{
    int n,k;
    cin>>n>>k;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    cout<<frog2(n-1,k)<<"\n";
    return 0;
}