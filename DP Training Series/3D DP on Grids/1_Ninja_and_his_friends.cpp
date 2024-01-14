#include <bits/stdc++.h>
#define for(i, m, n) for(int i = m; i < n; i++)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vvi vector<vector<int>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_vector(v, n) for(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) for(i, 0, m) for(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai int32_t main()
//#define int long long

using namespace std;

int memo(int i, int j1, int j2, vvi& grid, vector<vvi>& dp) {
    if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) return -1e9;
    if (i == grid.size()-1) return j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int mx = -1e9;
    for (alice, -1, 2) {
        for (bob, -1, 2) {
            int res = j1 == j2 ? grid[i][j1] : grid[i][j1] + grid[i][j2];
            mx = max(mx, res + memo(i+1, j1+alice, j2+bob, grid, dp));
        }
    }

    return dp[i][j1][j2] = mx;
}

int Solution(vvi& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vvi> dp(n, vvi(m, vi(m, -1)));
    return memo(0, 0, m-1, grid, dp);
}

Bankai {
    Eat Sleep Repeat

    {
        input(n) input(m)
        vvi grid(n, vi(m));
        input_2dvector(grid, n, m)

        cout<<Solution(grid)<<"\n";
    }

    return 0;
}

//note: go through tabulation again, understand the base cases being taken in case of tabulation. 