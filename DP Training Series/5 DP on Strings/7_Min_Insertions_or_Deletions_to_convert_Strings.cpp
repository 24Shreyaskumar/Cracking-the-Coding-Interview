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

//variation of lcs, return ((n-prev[m]) + (m-prev[m])) instead of prev[m].
int Solution(string& s, string& t) {
    sz(n, s) sz(m, t)
    vector<int> prev(m+1, 0), cur(m+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cur[j] = s[i-1] == t[j-1] ? prev[j-1] + 1 : max(prev[j], cur[j-1]);
        }

        prev = cur;
    }

    return n + m - 2*prev[m];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s) input_str(t)
        cout<<Solution(s, t)<<"\n";
    }

    return 0;
}