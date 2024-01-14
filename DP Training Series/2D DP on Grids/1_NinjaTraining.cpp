//state diagram method.

#include <bits/stdc++.h>
using namespace std;

int Solution(vector<vector<int>>& points) {
    int days = points.size();
    vector<vector<int>> dp(3, vector<int>(days+1, 0)); 
    dp[0][0] = points[0][0], dp[1][0] = points[0][1], dp[2][0] = points[0][2];

    for (int i = 1; i < days; i++) {
        dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + points[i][0];
        dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + points[i][1];
        dp[2][i] = max(dp[0][i-1], dp[1][i-1]) + points[i][2];
    }

    return max(dp[0][days-1], max(dp[1][days-1], dp[2][days-1]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int days; cin>>days;
        vector<vector<int>> points(days, vector<int>(3));
        for (int i = 0; i < days; i++) {
            for (int j = 0; j < 3; j++) cin>>points[i][j];
        }

        cout<<Solution(points)<<"\n";
    }

    return 0;
}