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
#define int long long

using namespace std;

int memo(int i, int c, vi& wt, vi& val, vvi& dp){
    if (i == 0) return (int)((c / wt[0]) * val[0]); //as we can take this multiple times, hence if cap is 4 and wt[0] = 1, then we can take the wt[0] 4 times as c / wt[0] = 4
    if (dp[i][c] != -1) return dp[i][c];

    int dontPick = memo(i-1, c, wt, val, dp);
    int pick = wt[i] <= c ? memo(i-1, c-wt[i], wt, val, dp) + val[i] : 0;
    int pickSame = wt[i] <= c ? memo(i, c-wt[i], wt, val, dp) + val[i] : 0;

    return dp[i][c] = max(max(pick, pickSame), dontPick);
}

int Solution(int n, int capacity, vi& wt, vi& val) {
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    //return memo(n-1, capacity, wt, val, dp);

    for(w, 0, capacity+1) dp[0][w] = (int)(w / wt[0]) * val[0];

    for (i, 1, n) {
        for (w, 0, capacity+1) {
            int dontPick = dp[i-1][w];
            int pick = wt[i] <= w ? dp[i-1][w-wt[i]] + val[i] : -1e9;
            int pickSame = wt[i] <= w ? dp[i][w-wt[i]] + val[i] : -1e9;
            dp[i][w] = max(dontPick, max(pick, pickSame));
        }
    } 

    return dp[n-1][capacity];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(capacity)
        vi wt(n), val(n);
        input_vector(wt, n) input_vector(val, n);

        cout<<Solution(n, capacity, wt, val)<<"\n";
    }

    return 0;
}