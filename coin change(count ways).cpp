#include<iostream>
#include<vector>
using namespace std;
long long Count(vector<int>&coins,int sum)
{
    vector<long long>dp(sum+1,0);
    dp[0]=1;
    for(int c:coins)
    {
        for(int i=c;i<=sum;i++)
        {
            
                dp[i]=(dp[i]+dp[i-c]);
            
        }
    }
    return dp[sum];
}
int main()
{
    int n,sum;
    cin>>n>>sum;
    vector<int>coins(n);
    for(int i=0;i<n;i++)
    {
        cin>>coins[i];
    }
    cout<<Count(coins,sum)<<"\n";
    return 0;
}