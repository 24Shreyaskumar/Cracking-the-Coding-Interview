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

bool isAllStars(string& p, int j) {
    for (int it = 0; it < j; it++) if (p[it] != '*') return false;
    return true;
}

bool memo(int i, int j, string& s, string& p, vvi& dp) {
    //base conditions:
    if (!i && j) return isAllStars(p, j);
    if (i && !j) return false;
    if (!i && !j) return true;
    if (dp[i][j] != -1) return dp[i][j];

    //recursive logic:
    if (s[i-1] == p[j-1] || p[j-1] == '?') return dp[i][j] = memo(i-1, j-1, s, p, dp);
    else if (p[j-1] == '*') return dp[i][j] = memo(i-1, j, s, p, dp) | memo(i, j-1, s, p, dp);
    return dp[i][j] = false; 
}

bool Solution(string s, string p) {
    sz(n, s) sz(m, p)
    vector<bool> prev(m+1, 0), cur(m+1, 0);

    prev[0] = 1, cur[0] = 0;
    FOR (j, 1, m+1) cur[j] = isAllStars(p, j);

    FOR (i, 1, n+1) {
        FOR (j, 1, m+1) {
            if (s[i-1] == p[j-1] || p[j-1] == '?') cur[j] = prev[j-1];
            else if (p[j-1] == '*') cur[j] = prev[j] | cur[j-1];
            else cur[j] = 0;
        }

        prev = cur;
    }

    return prev[m];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s) input_str(p)
        cout<<Solution(s, p)<<"\n";
    }

    return 0;
}