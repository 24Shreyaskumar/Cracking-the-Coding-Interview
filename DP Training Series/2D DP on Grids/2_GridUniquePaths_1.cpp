#include <bits/stdc++.h>
using namespace std;

int Solution(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[1][0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    return dp[m][n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int m, n; cin>>m>>n;
        cout<<Solution(m, n)<<"\n";
    }

    return 0;
}