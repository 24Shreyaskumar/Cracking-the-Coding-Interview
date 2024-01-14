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
//#define int long long

using namespace std;

int memo(int i, int j, vi& cuts, vvi& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mn = 1e9;
    for (int k = i; k <= j; k++) {
        int cost = memo(i, k-1, cuts, dp) + memo(k+1, j, cuts, dp) + cuts[j+1] - cuts[i-1];
        mn = min(mn, cost);
    }

    return dp[i][j] = mn;
}

int Solution(int n, vi& cuts) {
    sz(c, cuts)
    cuts.insert(cuts.end(), {0, n});
    SORT(cuts)
    vvi dp(c+2, vi(c+2, 0));
    //return memo(1, c, cuts, dp);

    FORD (i, c, 1) {
        FOR (j, i, c) {
            int mn = 1e9;
            FOR (k, i, j+1) {
                int cost = dp[i][k-1] + dp[k+1][j] + cuts[j+1] - cuts[i-1];
                mn = min(mn, cost);
            }
            dp[i][j] = mn;
        }
    }

    return dp[1][c];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(c) input(n)
        vi nums(c);
        input_vector(nums, c)

        cout<<Solution(n, nums)<<nl;
    }

    return 0;
}