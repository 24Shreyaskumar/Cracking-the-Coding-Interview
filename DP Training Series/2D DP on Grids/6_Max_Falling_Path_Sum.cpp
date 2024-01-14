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
#define input_2dvector(v, m, n) for(i, 0, m) for(j, 0, n) cin>>v[m][n];
#define size(n, ds) int n = ds.size();
#define Bankai int32_t main()
//#define int long long

using namespace std;

int Solution(int n, vvi& nums) {
    if (n == 1) return nums[0][0];
    int ans = INT_MAX;

    for (i, 1, n) {
        for (j, 0, n) {
            if (!j and j+1 < n) nums[i][j] += min(nums[i-1][j], nums[i-1][j+1]);
            else if (j and j+1 >= n) nums[i][j] += min(nums[i-1][j], nums[i-1][j-1]);
            else if (j and j+1 < n) nums[i][j] += min(nums[i-1][j], min(nums[i-1][j-1], nums[i-1][j+1]));
            if (i == n-1) ans = min(ans, nums[i][j]);
        }
    } 

    return ans;
}

Bankai {
    Eat Sleep Repeat

    {
        input(n)
        vvi nums(n, vi(n));
        input_2dvector(nums, n, n);

        cout<<Solution(n, nums)<<"\n";
    }

    return 0;
}

//To do later: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/