#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int minCoins(vector<int>&coins,int sum)
{
   vector<int>dp(sum+1,INT_MAX);
   dp[0]=0;
   for(int i=1;i<=sum;i++)
   {
    for(int c:coins)
    {
        if(i-c>=0 && dp[i-c]!=INT_MAX)
        {
            dp[i]=min(dp[i],1+dp[i-c]);
        }
    }
   }
   return (dp[sum]==INT_MAX)?-1:dp[sum];
}
int main()
{
    int n,sum;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cin>>sum;
    cout<<minCoins(coins,sum);
    return 0;
}