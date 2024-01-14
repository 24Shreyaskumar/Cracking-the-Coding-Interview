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

//space optimised tabulation
int Solution(string& t1, string& t2) {
    sz(n, t1) sz(m, t2);
    vi prev(m+1, 0), cur(m+1, 0);

    FOR (i, 1, n+1) {
        FOR (j, 1, m+1) {
            cur[j] = t1[i-1] == t2[j-1] ? prev[j-1] + 1 : max(prev[j], cur[i-1]);
        }

        prev = cur;
    }

    return prev[m];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(t1) input_str(t2)
        cout<<Solution(t1, t2)<<"\n";
    }

    return 0;
}