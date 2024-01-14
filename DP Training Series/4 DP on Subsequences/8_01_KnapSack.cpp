#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for (int i = m; i >= n; i--)
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
#define mod ((int) 1e9 + 7)
//#define int long long

using namespace std;

int memo(int i, int cap, vi& wt, vi& val, vvi& dp) {
    if (!i) return wt[0] <= cap ? val[0] : 0;
    if (dp[i][cap] != -1) return dp[i][cap];

    int pick = wt[i] <= cap ? memo(i-1, cap-wt[i], wt, val, dp) + val[i] : 0;
    int dontPick = memo(i-1, cap, wt, val, dp);

    return dp[i][cap] = max(pick, dontPick); 
}

int Solution(int n, int capacity, vi& wt, vi& val) {
    // vvi dp(n, vi(capacity+1, -1));
    // return memo(n-1, capacity, wt, val, dp);

    vi prev(capacity+1, 0), cur(capacity+1, 0);

    FOR (cap, 0, capacity+1) prev[cap] = wt[0] <= cap ? val[0] : 0;

    //logic rectified
    FOR (i, 1, n) {
        FORD(cap, capacity+1, 0) {
            int pick = wt[i] <= cap ? prev[cap-wt[i]] + val[i] : 0;
            int dontPick = prev[cap];
            cur[cap] = max(pick, dontPick);
        }

        prev = cur;
    }

    return prev[capacity];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(capacity)
        vi wt(n), val(n);
        input_vector(wt, n) input_vector(val, n)

        cout<<Solution(n, capacity, wt, val)<<"\n";
    }

    return 0;
}

//note : rectify space optimized tabulation, instead of moving cap from 0 to capacity, we need to move in oppo dir, i.e, from capacity to 0. for reason refer to striver sheet.