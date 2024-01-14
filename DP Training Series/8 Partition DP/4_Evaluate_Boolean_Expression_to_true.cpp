#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define REP(i, m, n, j) for(int i = m; i < n; i+=j);
#define FORD(i, m, n) for(int i = m; i >= n; i--)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvvi vector<vvi>
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
#define ll long long

using namespace std;

int memo(int i, int j, int isT, string& exp, vvvi& dp) {
    if (i > j) return 0;
    if (i == j) return isT ? exp[i] == 'T' : exp[i] == 'F';
    if (dp[i][j][isT] != -1) return dp[i][j][isT];

    ll count = 0;
    FOR (k, i+1, j) {
        ll lt = memo(i, k-1, 1, exp, dp);
        ll lf = memo(i, k-1, 0, exp, dp);
        ll rt = memo(k+1, j, 1, exp, dp);
        ll rf = memo(k+1, j, 0, exp, dp);

        if (exp[k] == '|') {
            if (isT) count += (lt*rt) + (lt*rf) + (lf*rt);
            else count += lf*rf;
        }

        else if (exp[k] == '&') {
            if (isT) count += lt*rt;
            else count += (lt*rf) + (lf*rt) + (lf*rf);
        }

        else {
            if (isT) count += (lt*rf) + (lf*rt);
            else count += (lt*rt) + (lf*rf);
        }

        ++k;
    }

    return dp[i][j][isT] = count;
}

int Solution(string exp) {
    sz(n, exp)
    vvvi dp(n+1, vvi(n+1, vi(2, 0)));
    //return memo(0, n-1, 1, exp, dp);

    FORD (i, n-1, 0) {
        FOR (j, i, n) {
            FOR (isT, 0, 2) {
                if (i == j) {
                    dp[i][j][isT] = isT ? exp[i] == 'T' : exp[i] == 'F';
                    continue;
                }
                
                int count = 0;
                FOR (k, i+1, j) {
                    ll lt = dp[i][k-1][1];
                    ll lf = dp[i][k-1][0];
                    ll rt = dp[k+1][j][1];
                    ll rf = dp[k+1][j][0];

                    if (exp[k] == '|') {
                        if (isT) count += lt*rt + lt*rf + lf*rt;
                        else count += lf*rf;
                    }

                    else if (exp[k] == '&') {
                        if (isT) count += lt*rt;
                        else count += lt*rf + lf*rt + lf*rf;
                    }

                    else {
                        if (isT) count += lt*rf + lf*rt;
                        else count += lt*rt + lf*rf;
                    }
                }

                dp[i][j][isT] = count;
            }
        }
    }

    return dp[0][n-1][1];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input_str(exp);
        cout<<Solution(exp)<<nl;
    }

    return 0;
}