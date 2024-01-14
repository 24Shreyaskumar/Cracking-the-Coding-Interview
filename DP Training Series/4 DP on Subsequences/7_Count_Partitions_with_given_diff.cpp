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
#define mod ((int) 1e9 + 7)
#define Bankai_Tensa_Zangetsu int32_t main()
//#define int long long

using namespace std;

//memoization
int memo(int i, int sum, vi& nums, vvi& dp) {
    if (!i) return !sum && !nums[0] ? 2 : !sum || sum == nums[0] ? 1 : 0;
    if (dp[i][sum] != -1) return dp[i][sum];

    int pick = nums[i] <= sum ? memo(i-1, sum-nums[i], nums, dp) : 0;
    int dontPick = memo(i-1, sum, nums, dp);

    return dp[i][sum] = (pick + dontPick) % mod;
}

//space optimised tabulation
int Solution(int n, int d, vi& nums) {
    int og = 0;
    fe (i, nums) og += i;
    if (og - d < 0 || (og - d) & 1) return 0;
    int sum2 = (og - d) >> 1;

    // vvi dp(n, vi(sum2+1, -1));
    // return memo(n-1, sum2, nums, dp);

    vi prev(sum2+1, -1), cur(sum2+1, -1);
    prev[0] = nums[0] ? 2 : 1;
    FOR (sum, 1, sum2+1) prev[sum] = sum == nums[0] ? 1 : 0;

    FOR (i, 1, n) {
        FOR (sum, 0, sum2+1) {
            int pick = nums[i] <= sum ? prev[sum-nums[i]] : 0;
            int dontPick = prev[sum];
            cur[sum] = (pick + dontPick) % mod;
        } 

        prev = cur;
    }
    

    return prev[sum2];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(d)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, d, nums)<<"\n";
    }

    return 0;
}