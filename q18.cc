#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
const int MAXN = 1000000;

long long dp[MAXN + 1][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i <= MAXN; i++)
    {
        dp[i][0] = (4LL * dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] + 2LL * dp[i - 1][1]) % MOD;
    }

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % MOD << '\n';
    }
}