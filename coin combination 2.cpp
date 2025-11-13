#include<iostream>
#include<vector>
using namespace std;
const long long MOD=1e9+7;
long long coincombination(vector<int>&coins,int x)
{
    vector<long long>dp(x+1,0);
    dp[0]=1;
    for(int c:coins)
    {
        for(int i=c;i<=x;i++)
        dp[i]=(dp[i]+dp[i-c])%MOD;
    }
    return dp[x];
}
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    cout<<coincombination(coins,x);
}