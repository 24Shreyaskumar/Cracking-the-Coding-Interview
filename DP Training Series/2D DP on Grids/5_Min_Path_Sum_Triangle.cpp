#include <bits/stdc++.h>
#define for(i, m, n) for(int i = m; i < n; i++)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vvi vector<vector<int>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_vector(v, n) for(i, 0, n) cin>>v[i];
#define input_2dvector(v, n) for(i, 0, n) for(j, 0, i+1) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai int32_t main()

using namespace std;

int Solution(vvi& nums) {
    sz(n, nums)
    int ans = INT_MAX;

    for(i, 0, n) {
        for (j, 0, i+1) {
            if (!j && i) nums[i][j] += nums[i-1][j];
            else if (i && j == nums[i].size()-1) nums[i][j] += nums[i-1][j-1];
            else if (i && j) nums[i][j] += min(nums[i-1][j], nums[i-1][j-1]);
            if (i == n-1) ans = min(ans, nums[i][j]);
        }
    }

    return ans;
}

Bankai {
    Eat Sleep Repeat

    {
        input(n)
        vvi nums(n, vi(n, 0));
        input_2dvector(nums, n);

        cout<<Solution(nums)<<"\n";
    }

    return 0;
}