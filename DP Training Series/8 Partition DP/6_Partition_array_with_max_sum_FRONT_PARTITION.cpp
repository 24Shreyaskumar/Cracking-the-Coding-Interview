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
#define ll long long

using namespace std;

int Solution(int n, int k, vi& nums) {
    vector<int> dp(n+1, 0);

    FORD (i, n-1, 0) {
        int mx = -1e9, mx_sum = 0;
        FOR (j, i, n) {
            if (j-i+1 <= k) {
                mx = max(mx, nums[j]);
                mx_sum = max(mx_sum, dp[j+1] + (j-i+1)*mx);
            }
        }

        dp[i] = mx_sum;
    }

    return dp[0];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(k)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, k, nums)<<nl;
    }

    return 0;
}