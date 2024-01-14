#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for(int i = m; i >= n; i--)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define pb push_back
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

string Solution(string& s, string& t) {
    sz(n, s) sz(m, t)
    vector<pair<int, string>> prev(m+1, {0, ""}), cur(m+1, {0, ""});

    FOR (i, 1, n+1) {
        FOR (j, 1, m+1) {
            if (s[i-1] == t[j-1]) {
                cur[j].first = prev[j-1].first + 1;
                cur[j].second = prev[j-1].second; cur[j].second.pb(s[i-1]);
            }

            else cur[i] = prev[j].first >= cur[j-1].first ? prev[j] : cur[j-1];
        }

        prev = cur;
    }

    return prev[m].second;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(s) input_str(t)
        cout<<Solution(s, t)<<"\n";
    }

    return 0;
}