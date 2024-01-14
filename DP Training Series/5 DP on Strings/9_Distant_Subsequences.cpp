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
int Solution(string& s, string& t) {
    sz(n, s) sz(m, t)

    vector<int> prev(m+1, -1), cur(m+1, -1);
    prev[0] = cur[0] = 1;
    prev[1] = s[0] == t[0];

    FOR (j, 2, m+1) prev[j] = 0;

    FOR (i, 1, n) {
        FOR (j, 1, m) {
            int pick = s[i] == t[j-1] ? prev[j-1] : 0;
            int dontPick = prev[j];

            cur[j] = (pick + dontPick) % mod;
        }

        prev = cur;
    }

    return prev[m];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s) input_str(t);
        cout<<Solution(s, t)<<"\n";
    }

    return 0;
}