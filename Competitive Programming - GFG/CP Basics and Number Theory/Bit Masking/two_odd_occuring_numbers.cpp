// Task is to find the two number whose count of occurence is odd
// variation of one odd occuring number problem

#include <bits/stdc++.h>
using namespace std;

pair<int, int> Solve(int n, vector<int>& nums) {
    pair<int, int> res = {0, 0};
    int xorr = 0;
    for (auto i : nums) xorr ^= i;

    //Find the rightmost set bit in the xorr result
    int rightmost_set_bit = xorr & ~(xorr - 1);

    for (auto i : nums) {
        //Divide nums into 2 groups, one where the rightmost bit is set and other where not.
        (i & rightmost_set_bit) ? res.first ^= i : res.second ^= i;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin>>nums[i];
        pair<int, int> res = Solve(n, nums);
        cout<<res.first<<" "<<res.second;
    }

    return 0;
}