#include <bits/stdc++.h>
using namespace std;

int Solution(int n, vector<int>& nums) {
    vector<pair<int, int>> dp(n + 1, {0, 0});
    dp[0].first = nums[0];

    for (int i = 1; i < n; i++) {
        dp[i].first = dp[i-1].second + nums[i];
        dp[i].second = max(dp[i-1].first, dp[i-1].second);
    }

    return max(dp[n-1].first, dp[n-1].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin>>nums[i];

        cout<<Solution(n, nums)<<"\n";
    }

    return 0;
}