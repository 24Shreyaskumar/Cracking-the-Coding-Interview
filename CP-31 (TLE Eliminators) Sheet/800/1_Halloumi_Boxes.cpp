/*Created by @shreyaskumar24*/

#include <bits/stdc++.h>
#define FOR(i, m, n, inc) for(int i = m; i < n; i+=inc)
#define FORD(i, m, n, dec) for(int i = m; i >= n; i-=dec)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define ppi pair<int, int>
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
#define input_vector(v, n) FOR(i, 0, n, 1) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m, 1) FOR(j, 0, n, 1) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
#define nl "\n"
#define nline cout<<nl;
#define ll long long
#define MOD (int)(1e9 + 7)

using namespace std;

string Solve(int n, int k, vi& nums) {
    int i = 0;
    for (; i < n-1; i++)
        if (nums[i] > nums[i+1]) break;

    return k == 1 && i != n-1? "NO" : "YES";
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        int n, k;
        cin>>n>>k;
        vi nums(n);
        input_vector(nums, n)

        cout<<Solve(n, k, nums)<<nl;
    }

    return 0;
}