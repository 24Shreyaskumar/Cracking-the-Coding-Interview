#include <bits/stdc++.h>
using namespace std;

int Solution(vector<vector<int>>& maze) {
    int m = maze.size(), n = maze[0].size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j<= n; j++) {
            if (!maze[i-1][j-1]) dp[i][j] = dp[i-1][j] + dp[i][j-1];
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
        vector<vector<int>> maze(m, vector<int>(n, 0));
        for (int i =0; i < m; i++) {
            for (int j = 0; j < n; j++) cin>>maze[i][j];
        }

        cout<<Solution(maze)<<"\n";
    }

    return 0;
}