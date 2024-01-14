#include <bits/stdc++.h>
#define for(i, m, n) for(int i = m; i < n; i++)
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
#define input_vector(v, n) for(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) for(i, 0, m) for(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
//#define int long long

using namespace std;

//memoization
int memo(int i, int n, vi& prices, vvi& dp) {
    if (i == 0) return n * prices[0];
    if (dp[i][n] != -1) return dp[i][n];

    int dontCut = memo(i-1, n, prices, dp);
    int cutSame = i <= n ? memo(i, n-i, prices, dp) + prices[i] : -1e9;

    dp[i][n] = max(cutSame, dontCut);
}

//tabulation
int Solution(int n, vi& prices) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    for (num, 0, n+1) dp[0][num] = num * prices[0];

    for (i, 1, n) {
        for (num, 0, n+1) { 
            int dontCut = dp[i-1][num];
            int cut = i+1 <= num ? dp[i][num-i-1] + prices[i] : -1e9;
            dp[i][num] = max(cut, dontCut);
        }
    }

    return dp[n-1][n];
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