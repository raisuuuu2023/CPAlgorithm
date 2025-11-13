#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n,x;
    cin>>n>>x;
    vector<int>h(n),s(n);
    for(int i=0;i<n;i++) cin>>h[i];
    for(int i=0;i<n;i++) cin>>s[i];
    vector<int>dp(x+1,0);
    for(int i=0;i<n;i++)
    {
        for(int cost=x;cost>=h[i];cost--)
        {
            dp[cost]=max(dp[cost],s[i]+dp[cost-h[i]]);
        }
    }
    cout<<dp[x]<<"\n";
    return 0;
}