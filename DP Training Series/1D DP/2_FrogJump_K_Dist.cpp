#include <bits/stdc++.h>
using namespace std;

int Solution(int k, vector<int>& heights) {
    int n = heights.size();
    vector<int> dist(k+1, 0);
    for (int i = 1; i < n; i++) {
        dist[k] = dist[k-1] + abs(heights[i] - heights[i-1]);
        int j = i-2, c = 2;
        while (j >= 0 && i - j <= k) {
            dist[k] = min(dist[k], dist[k-c] + abs(heights[i] - heights[i - c]));
            j--, c++;
        }
        
        for (int x = 0; x < k; x++) dist[x] = dist[x+1]; 
    }

    for (auto i : dist) cout<<i<<" ";
    cout<<endl;

    return dist[k-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin>>nums[i];

    cout<<Solution(k, nums)<<"\n";

    return 0;
}