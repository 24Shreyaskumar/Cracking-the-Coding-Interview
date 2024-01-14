#include <bits/stdc++.h>
#define for(i, m, n) for(int i = m; i < n; i++)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<bool>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_vector(v, n) for(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) for(i, 0, m) for(j, 0, n) cin>>v[m][n];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
//#define int long long

using namespace std;

//memoization
bool memo(int i, int k, vi& nums, vvi& dp) {
    if (!k) return true;
    if (!i) return nums[0] == k;
    if (dp[i][k] != -1) return dp[i][k];

    bool pick = k >= nums[i] ? memo(i-1, k-nums[i], nums, dp) : false;
    bool dontPick = memo(i-1, k, nums, dp);

    return dp[i][k] = pick || dontPick;
}

//tabulation
string tabulation(int n, int k, vi& nums) {
    vvi dp(n, vb(k+1, -1));
    //return memo(nums.size()-1, k, nums, dp) ? "yes" : "no";
    for(i, 0, n) dp[i][0] = true;
    if (nums[0] <= k) dp[0][nums[0]] = true;

    for (i, 1, n) {
        for (j, 1, k+1) {
            bool dontPick = dp[i-1][j];
            bool pick = nums[i] <= j ? dp[i-1][j-nums[i]] : false;
            dp[i][j] = pick || dontPick;
        }
    }

    return dp[n-1][k] ? "yes" : "no";
}


//space optimised
string Solution(int k, vi& nums) {
    int n = nums.size();
    vb prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = 1;
    if (nums[0] <= k) prev[nums[0]] = true;

    for (i, 1, n) {
        for (j, 1, k+1) {
            bool pick = nums[i] <= j ? prev[j-nums[i]] : 0;
            bool dontPick = prev[j];
            cur[j] = pick | dontPick;
        }
        prev = cur;
    }

    return prev[k] ? "yes" : "no";
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(k)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(k, nums)<<"\n";
    }

    return 0;
}