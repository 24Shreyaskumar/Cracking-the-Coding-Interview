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

//space optimised tabulation.
//special case of Longest Common Subsequence.
int Solution(string s, string t) {
    sz(n, s) sz(m, t);
    vi prev(m+1, 0), cur(m+1, 0);
    int mx = 0;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            cur[j] = s[i-1] == t[j-1] ? prev[j-1] + 1 : 0;
            mx = max(mx, cur[j]);
        }

        prev = cur;
    }

    return mx;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s) input_str(t)
        cout<<Solution(s, t)<<"\n";
    }

    return 0;
}