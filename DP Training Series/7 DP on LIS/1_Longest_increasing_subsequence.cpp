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

//memoized approach using striver's method.
int memo(int i, int prev, vi& nums, vvi& dp) {
    if (i == nums.size()) return 0;
    if (dp[i][prev+1] != -1) return dp[i][prev];

    int pick = prev == -1 || nums[i] > nums[prev] ? memo(i+1, i, nums, dp) + 1 : 0;
    int dontPick = memo(i+1, prev, nums, dp);

    return dp[i][prev+1] = max(pick, dontPick);
}


//tabulation using aansh sir's method.
int tabulation_aansh(int n, vi&nums) {
    int lis = 1;
    vi dp(n, 1);

    FOR(i, 0, n) {
        FOR (j, 0, i) {
            dp[i] = nums[i] > nums[j] ? max(dp[i], dp[j]+1) : dp[i];
        }

        lis = max(lis, dp[i]);
    }

    return lis;
} 


//most optimised method:
int binarySearch(vi& lis, int num) {
    int l = 0, r = lis.size()-1;

    while (l <= r) {
        int mid = l + (r-l) / 2;
        if (lis[mid] > num) r = mid-1;
        else l = mid+1;
    }

    return l;
}

//note: this solution doesn't store the longest increasing subsequence in the extra vector.
int Solution_nlogn(int n, vi& nums) {
    vi lis;
    lis.pb(nums[0]);

    FOR(i, 1, n) {
        int ind = binarySearch(lis, nums[i]);
        if (ind >= lis.size()) lis.pb(nums[i]);
        else lis[ind] = nums[i];
    }

    return lis.size();
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution_nlogn(n, nums)<<"\n";
    }

    return 0;
}