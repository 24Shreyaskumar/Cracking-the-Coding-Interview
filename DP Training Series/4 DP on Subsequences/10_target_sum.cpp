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
#define input_vector(v, n) FOR(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m) FOR(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
//#define int long long

using namespace std;

//sapce optimised tabulation
int Solution(int n, int target, vi& nums) {
    target = abs(target);
    int sum = 0;
    fe (i, nums) sum += i;

    if (target > sum || (sum - target) & 1) return 0;
    sum = (sum - target) >> 1;

    vi prev(sum+1, -1), cur(sum+1, -1);

    prev[0] = !nums[0] ? 2 : 1;

    FOR (s, 1, sum+1) prev[s] = nums[0] == s ? 1 : 0;

    FOR (i, 1, n) {
        FOR (s, 0, sum+1) {
            int pick = nums[i] <= s ? prev[s-nums[i]] : 0;
            int dontPick = prev[s];
            cur[s] = (pick + dontPick) % ((int)1e9+7);
        }

        prev = cur;
    }

    return prev[sum];
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n) input(target)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solution(n, target, nums)<<"\n";
    }

    return 0;
}