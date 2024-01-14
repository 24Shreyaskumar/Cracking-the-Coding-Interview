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
//#define int long long

using namespace std;


int Solution(int fee, vi& prices) {
    sz(n, prices)
    int loss = -prices[0], profit = 0, p = 0, p2p = -mod;

    FOR (i, 1, n) {
        p2p = p;
        p = profit;
        profit = max(p, loss + prices[i] - fee);
        loss = max(loss, p2p - prices[i]);
    }

    return profit;
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

