#include<iostream>
#include<vector>
#include<limits>
using namespace std;
int dp[310][1010];
int func1(int idx,int amount,vector<int>&coins)
{
    if(amount==0) return 1;
    if(idx<0) return 0;
    if(dp[idx][amount]!=-1) return dp[idx][amount];
    int ways=0;
    for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[idx])
    {
        ways+=func1(idx-1,amount-coin_amount,coins);
    }
    return dp[idx][amount]=ways;
}
int coinchange(vector<int>&coins,int amount)
{
     memset(dp,-1,sizeof(dp));
     return func1(coins.size()-1,amount,coins);
}
int main()
{
    vector<int>coins={1,2,3};
    int amount=5;
    cout<<coinchange(coins,amount);
    return 0;
}