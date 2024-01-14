#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for(int i = m; i >= n; i--)
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
#define mod ((int) 1e9 + 7)
#define int long long

using namespace std;

int memo(int i, int amount, vi& nums, vvi& dp) {
    if (!i) return amount % nums[0] == 0;
    if (dp[i][amount] != -1) return dp[i][amount];

    int pick = nums[i] <= amount ? memo(i, amount-nums[i], nums, dp) : 0; //note we are note decreasing i, because we can even pick the same element multiple times.
    int dontPick = memo(i-1, amount, nums, dp);

    return dp[i][amount] = pick + dontPick;
}

int Solution(int amount, vi& nums) {
    sz(n, nums);
    // vvi dp(n, vi(amount+1, -1));
    // return memo(n-1, amount, nums, dp);

    vector<int> prev(amount+1, -1), cur(amount+1, -1);

    FOR (a, 0, amount+1) prev[a] = a % nums[0] == 0;

    FOR (i, 1, n) {
        FOR (a, 0, amount+1) {
            int pick = nums[i] <= a ? cur[a-nums[i]] : 0;
            int dontPick = prev[a];
            cur[a] = pick + dontPick;
        }

        prev = cur;
    }

    return prev[amount];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, nums)<<"\n";
    }

    return 0;
}