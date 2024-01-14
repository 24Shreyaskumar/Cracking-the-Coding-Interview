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

static bool comp(string& s, string& t) {
    if (s.size() == t.size()) return s < t;
    return s.size() < t.size();
}

bool eq(string s, string t) {
    int n = s.size();

    for (int i = 0, j = 0, c = 0; i < n && j < n-1; i++, j++) {
        if (s[i] != t[j]) {
            i++, c++;
            if (c > 1) return false;
        }
    }

    return true;
}

int Solution(int n, vector<string>& words) {
    sort(all(words), comp);
    vi dp(n, 1);
    int lis = 1;
    
    FOR(i, 0, n) {
        FOR(j, 0, i) {
            if (words[i].size() == words[j].size()+1 && eq(words[i], words[j])) dp[i] = max(dp[i], dp[j]+1);
        }

        lis = max(lis, dp[i]);
    }

    return lis;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vector<string> words(n);
        input_vector(words, n)

        cout<<Solution(n, words)<<nl;
    }

    return 0;
}