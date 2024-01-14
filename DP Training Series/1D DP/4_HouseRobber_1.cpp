//same logic as 3rd dp que, only que name is different. But will going to use a different way to represent dp.


#include <bits/stdc++.h>
using namespace std;

int Solution(int n, vector<int>& nums) {
    vector<int> dp(n+1, 0);
    dp[0] = 0, dp[1] = nums[0];
    for (int i = 2; i <= n; i++) dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
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

        cout<<Solution(n, nums)<<"\n";
    }

    return 0;
}