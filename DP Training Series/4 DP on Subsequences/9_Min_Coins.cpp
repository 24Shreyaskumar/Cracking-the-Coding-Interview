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

//memoization
int memo(int i, int amount, vi& coins, vvi& dp) {
    if (!i) return amount % coins[0] ? 1e9 : amount / coins[0];
    if (dp[i][amount] != -1) return dp[i][amount];

    int pick = coins[i] <= amount ? memo(i-1, amount-coins[i], coins, dp) + 1 : 0;
    int pickSame = coins[i] <= amount ? memo(i, amount-coins[i], coins, dp) + 1 : 0;
    int dontPick = memo(i-1, amount, coins, dp) + 1;

    return dp[i][amount] = min(min(pick, pickSame), dontPick);
}


//space optimised tabulation
int Solution(int n, int amount, vi& coins) {
    // vvi dp(n, vi(amount+1, -1));
    // int ans = memo(n-1, amount, coins, dp);
    // return ans == 1e9 ? -1 : ans;

    vi prev(amount+1, -1), cur(amount+1, -1);

    FOR (a, 0, amount) prev[a] = a % coins[0] ? 1e9 : a / coins[0];

    FOR (i, 1, n) {
        FOR (a, 0, amount) {
            int pick = coins[i] <= a ? prev[a-coins[i]] + 1 : 1e9;
            int pickSame = coins[i] <= a ? cur[a-coins[i]] + 1 : 1e9;
            int dontPick = prev[a];

            cur[a] = min(min(pick, pickSame), dontPick);
        }

        prev = cur;
    } 

    return prev[amount] == 1e9 ? -1 : prev[amount];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(amount)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, amount, nums)<<"\n";
    }

    return 0;
}