#include <iostream>
#include <vector>
#include <string>
using namespace std;

string LCS(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string ans;
    int x=n,y=m;
    while(x>0 && y>0)
    {
        if(s[x-1]==t[y-1])
        {
            ans=s[x-1]+ans;
            x--;
            y--;
        }
        else if(dp[x-1][y]>dp[x][y-1])
        {
            x--;
        }
        else
        {
            y--;
        }
    }
    cout<<ans<<"\n";
    return ans;
}

int main() {
    string s,t;
    cin>>s>>t;
    LCS(s, t);  
    return 0;
}
