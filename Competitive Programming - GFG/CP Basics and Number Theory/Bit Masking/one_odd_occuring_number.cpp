//Task is to find the only number that occurs odd number of times in the array.

#include <bits/stdc++.h>
using namespace std;

int Solve(int n, vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < n; i++) res ^= nums[i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin>>nums[i];
        cout<<Solve(n, nums)<<"\n";
    }

    return 0;
}