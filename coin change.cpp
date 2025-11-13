#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int dp[10010];
int func(vector<int>&arr,int amount)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT_MAX;
    for(int coin:arr)
    {
        if(amount-coin>=0 )
         ans=min(ans+0LL,func(arr,amount-coin)+1LL);
    }
    return dp[amount]=ans;
}
int coinchange(vector<int>&arr,int amount)
{
    memset(dp,-1,sizeof(dp));
    int ans=func(arr,amount);
    return ans==INT_MAX?-1:ans;
}
int main()
{
    int N,amount;
    cin>>N>>amount;
    vector<int>arr(N);
    for(int i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cout<<coinchange(arr,amount);
    return 0;
}