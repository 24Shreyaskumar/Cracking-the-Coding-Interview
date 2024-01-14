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
//#define int long long

using namespace std;

bool memo(int i, int sum, vi& nums, vvi& dp) {
    if (!sum) return 1;
    if (!i) return nums[0] == sum;
    if (dp[i][sum] != -1) return dp[i][sum];

    bool pick = nums[i] <= sum ? memo(i-1, sum-nums[i], nums, dp) : 0;
    bool dontPick = memo(i-1, sum, nums, dp);

    return dp[i][sum] = pick | dontPick;
}

int Solution(int n, vi& nums) {
    int n = nums.size(), ogSum = 0;
    fe (i, nums) ogSum += i;
    vvb dp(n, vb(ogSum+1, 0));

    //for (int sum = 0; sum <= ogSum; sum++) memo(n-1, sum, nums, dp);

    FOR (i, 0, n) dp[i][0] = 1;

    //FOR (sum, 0, ogSum+1) {
        if (nums[0] <= ogSum) dp[0][nums[0]] = 1;

        FOR (i, 1, n) {
            FOR (k, 0, ogSum+1) {
                bool pick = nums[i] <= k ? dp[i-1][k-nums[i]] : 0;
                bool dontPick = dp[i-1][k];
                dp[i][k] = pick | dontPick;
            }
        }
    //}

    int mn = 1e9;
    ogSum >>= 1;
    ogSum++;
    FOR (sum, 0, ogSum+1) if (dp[n-1][sum]) mn = min(mn, abs(ogSum - 2*sum));

    return mn; 
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

//note: optimise tabulation. 