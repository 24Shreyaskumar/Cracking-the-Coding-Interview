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
#define input_str(s) string s; cin>>s;
#define input_vector(v, n) FOR(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m) FOR(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
#define int long long

using namespace std;

int memo(int i, int buy, int k, vi& prices, vector<vvi>& dp) {
    if (i == prices.size() || !k) return 0;
    if (dp[i][buy][k] != -1) return  dp[i][buy][k];

    if (!buy) {
        int loss = memo(i+1, 1, k, prices, dp) - prices[i];
        int skip = memo(i+1, 0, k, prices, dp);
        return dp[i][buy][k] = max(loss, skip);
    }

    int profit = memo(i+1, 0, k-1, prices, dp) + prices[i];
    int skip = memo(i+1, 1, k, prices, dp); 
    return dp[i][buy][k] = max(profit, skip);
}

int Solution(int K, vi& prices) {
    sz(n, prices)
    vvi prev(2, vi(K+1, 0)), cur(2, vi(K+1, 0));
    //return memo(0, 0, k, prices,  dp);

    FORD (i, n-1, 0) {
        FOR (buy, 0, 2) {
            FOR (k, 1, K+1) {
                if (!buy) {
                    int loss = prev[1][k] - prices[i];
                    int skip = prev[0][k];
                    cur[buy][k] = max(loss, skip);
                }

                else {
                    int profit = prev[0][k-1] + prices[i];
                    int skip = prev[1][k];
                    cur[buy][k] = max(profit, skip);
                }
            }
        }
    }

    return prev[0][K];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(K)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(K, nums)<<"\n";
    }

    return 0;
}

//variation of buy and sell stocks 3. This problem provides a generalized solution for any number of transaction allowed.