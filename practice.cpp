#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int change(vector<int>&coins,int sum)
{
    const int INF=1e9;
    vector<int>dp(sum+1,INF);
    dp[0]=0;
    for(int i=1;i<=sum;i++)
    {
        for(int c:coins)
        {
            if(i-c>=0 && dp[i-c]!=INF)
            dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    return dp[sum]==INF?-1:dp[sum];
}
int main() {
    
    int N, amount;
    cin >> N >> amount;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
 
    cout << change(arr, amount);
    return 0;
}