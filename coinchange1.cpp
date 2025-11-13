#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MOD = 100000007;
int main() {
    int T;
    cin >> T;
    for (int t=1;t<=T;++t) {
        int n, K;
        cin>>n>>K;
        vector<int> A(n), C(n);
        for(int i=0;i<n;++i){
            cin>>A[i];
        }
        for(int i=0;i<n;++i){
            cin>>C[i];
        }

        vector<vector<int> > dp(n+1,vector<int>(K+1,0));
        dp[0][0]=1;

        for(int i=1;i<=n;++i) {
            for(int j=0;j<=K;++j){
                dp[i][j]=dp[i-1][j];
                for(int k=1;k<=C[i-1];++k) {
                    if(j>=k*A[i-1]) {
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k*A[i-1]])%MOD;
                    } else {
                        break;
                    }
                }
            }
        }

        cout<<"Case "<<t<<": "<<dp[n][K]<<endl;
    }
    return 0;
}