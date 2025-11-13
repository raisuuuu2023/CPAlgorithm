#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9+7;
int main() {
    int n;
    cin >> n;
    long long sum = 1LL * n * (n + 1) / 2;

    if (sum % 2) {
        cout << 0 << "\n";
        return 0;
    }

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int num = 1; num <= n; num++) {
        for (int s = target; s >= num; s--) {
            dp[s] = (dp[s] + dp[s - num]) % MOD;
        }
    }
    long long inv2 = (MOD + 1) / 2;
    cout << (dp[target] * inv2) % MOD << "\n";
}
