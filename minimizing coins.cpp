#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[1000010];
int minimizeCoin(vector<int>&coins,int amount)
{
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans=INT_MAX;
    for(int coin:coins)
    {
        if(amount-coin>=0)
        {
            int sub=minimizeCoin(coins,amount-coin);
            if(sub!=INT_MAX)
            ans=min(ans,sub+1);
        }
    }
    return dp[amount]=ans;
}
int coinChange(vector<int>&coins, int amount)
{
     memset(dp,-1,sizeof(dp));
     int ans=minimizeCoin(coins,amount);
     return ans==INT_MAX?-1:ans;
}
int main()
{
    int n,amount;
    cin>>n>>amount;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    cout<<coinChange(coins,amount);
    return 0;
}