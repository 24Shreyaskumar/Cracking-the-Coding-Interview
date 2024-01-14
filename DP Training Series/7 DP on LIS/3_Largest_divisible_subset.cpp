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
//#define int long long


using namespace std;

vi Solution(int n, vi& nums) {
    SORT(nums)
    vi lis;
    vvi dp(n);

    FOR (i, 0, n) {
        FOR (j, 0, i) {
            if (nums[i] % nums[j] == 0 && dp[i].size() < dp[j].size()+1) dp[i] = dp[j];
        }

        dp[i].pb(nums[i]);

        if (lis.size() < dp[i].size()) lis = dp[i];
    }

    return lis;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi nums(n);
        input_vector(nums, n)

        vi lis = Solution(n, nums);
        
        fe(i, lis) cout<<i<<" ";
        cout<<nl;
        newline
    }

    return 0;
}