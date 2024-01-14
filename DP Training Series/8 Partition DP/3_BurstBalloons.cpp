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
#define pb push_back
#define ppb pop_back
#define SORT(ds) sort(ds.begin(), ds.end());
#define all(ds) ds.begin(), ds.end()
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_str(s) string s; cin>>s;
#define input_vector(v, n) FOR(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m) FOR(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
#define nl "\n"
#define newline cout<<nl;
#define int long long

using namespace std;

int memo(int i, int j, vi& nums, vvi& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mx = -1e9;
    FOR (k, i, j+1) {
        int cur = nums[i-1]*nums[k]*nums[j+1];
        int coins = memo(i, k-1, nums, dp) + memo(k+1, j, nums, dp) + cur;
        mx = max(mx, coins);
    }

    return dp[i][j] = mx;
}

int Solution(int n, vi& nums) {
    nums.pb(1);
    nums.insert(nums.begin(),1);
    vvi dp(n+2, vi(n+2, 0));
    //return memo(1, n, nums, dp);

    FORD (i, n, 1) {
        FOR (j, i, n+1) {
            int mx = -1e9;
            FOR (k, i, j+1) {
                int cur = nums[i-1]*nums[k]*nums[j+1];
                int coins = dp[i][k-1] + dp[k+1][j] + cur;
                mx = max(mx, coins);
            }
            dp[i][j] = mx;
        }
    }

    return dp[1][n];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, nums)<<nl;
    }

    return 0;
}