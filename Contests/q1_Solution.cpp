#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for(int i = m; i >= n; i--)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vvb vector<vector<bool>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pb push_back
#define ppb pop_back
#define SORT(ds) sort(ds.begin(), ds.end());
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

int Solution(int n, vi& capacities) {
    vi prefixSum(n);
    prefixSum[0] = capacities[0];

    FOR (i, 1, n) prefixSum[i] = prefixSum[i-1] + capacities[i];

    umap lookup;
    int count = 0;

    FOR (i, 0, n) {
        if (lookup.find(capacities[i]) != lookup.end()) {
            int interior_capacity = prefixSum[i-1] - prefixSum[lookup[capacities[i]]];
            if (interior_capacity == capacities[i]) count++;
            else if (!interior_capacity) continue;
        }

        lookup[capacities[i]] = i;
    }

    return count;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi capacities(n);
        input_vector(capacities, n)
        cout<<Solution(n, capacities)<<nl;
    }

    return 0;
}