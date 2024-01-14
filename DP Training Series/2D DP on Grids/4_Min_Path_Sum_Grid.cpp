#include <bits/stdc++.h>
using namespace std;

int Solution(vector<vector<int>>& maze, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = maze[0][0];

    for (int i = 1; i < m; i++) dp[0][i] = dp[0][i-1] + maze[0][i];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i-1][0] + maze[i][0];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) dp[i][j] = maze[i][j] + min(dp[i-1][j], dp[i][j-1]);
    }

    return dp[n-1][m-1];
} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n, m; cin>>n>>m;
        vector<vector<int>> maze(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) cin>>maze[i][j];
        }

        cout<<Solution(maze, n, m)<<"\n";
    }

    return 0;
}