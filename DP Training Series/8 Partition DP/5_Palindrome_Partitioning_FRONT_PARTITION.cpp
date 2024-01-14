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

bool isPal(int i, int j, string& s) {
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }

    return true;
}

int memo(int i, string& s, vi& dp) {
    if (i == s.size()) return 0;
    if (dp[i] != -1) return dp[i];

    int mn = 1e9;
    FOR (j, i, s.size()) {
        if (isPal(i, j, s)) mn = min(mn, memo(j+1, s, dp) + 1);
    }

    return dp[i] = mn;
}

int Solution(string s) {
    sz(n, s);
    vi dp(n+1, 0);
    //return memo(0, s, dp)-1;

    FORD (i, n-1, 0) {
        int mn = 1e9;
        FOR(j, i, n) if (isPal(i, j, s)) mn = min(mn, dp[j+1] + 1);
        dp[i] = mn;
    }

    return dp[0]-1;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s);
        cout<<Solution(s)<<nl;
    }

    return 0;
}