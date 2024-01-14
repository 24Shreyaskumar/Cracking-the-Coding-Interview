#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_vector(v, n) FOR(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m) FOR(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define int long long

using namespace std;

int memo(int i, int k, vi& nums, vvi& dp) {
    if (!k) return 1;
    if (!i) return nums[0] == k;
    if (dp[i][k] != -1) return dp[i][k];

    int pick = nums[i] <= k ? memo(i-1, k-nums[i], nums, dp) : 0;
    int dontPick = memo(i-1, k, nums, dp);

    return dp[i][k] = pick + dontPick;
}

int Solution(int k, vi& nums) {
    vvi dp(nums.size(), vi(k+1, -1));
    return memo(nums.size()-1, k, nums, dp);
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(k)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(k, nums)<<"\n";
    }

    stoi('1' + "Aaa");

    return 0;
}