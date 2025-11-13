#include <iostream>
#include <vector>
using namespace std;
const int MOD = 100000007;
int main() {
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int n, K;
        cin >> n >> K;
        vector<int> coins(n);
        for (int i = 0; i < n; ++i)
            cin >> coins[i];
        vector<int> dp(K + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = coins[i]; j <= K; ++j) {
                dp[j] = (dp[j] + dp[j - coins[i]]) % MOD;
            }
        }
        cout << "Case " << tc << ": " << dp[K] << "\n";
    }
    return 0;
}
