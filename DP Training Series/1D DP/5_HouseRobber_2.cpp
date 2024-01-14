//varitation of House Robber, difference is that the houses are arranged in a circular fashion, making the first and last house adjacent to each other.

#include <bits/stdc++.h>
using namespace std;

int Solution(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = nums[0];
    for(int i = 2; i <= 2; i++) dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin>>nums[i];

        vector<int> a(n-1), b(n-1);
        for (int i = 0; i < n-1; i++) a[i] = nums[i], b[i] = nums[i+1];

        int ans1 = Solution(a);
        int ans2 = Solution(b);

        cout<<max(ans1, ans2)<<"\n";
    }

    return 0;
}