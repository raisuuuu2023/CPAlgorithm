#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int editdistance(const string& str1,const string& str2)
{
    int n =str1.size();
    int m =str2.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
            else 
            dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
        }
    }
    return dp[n][m];
}
int main()
{
    string str1,str2;
    cin>>str1>>str2;
    int distance=editdistance(str1,str2);
    cout<<distance<<"\n";
    return 0;
}