#include <bits/stdc++.h>
using namespace std;

int Solution(int n, vector<int>& heights) {
    int prev2 = 0, prev = 0, cur = 0;

    for (int i = 1; i < n; i++) {
        cur = prev + abs(heights[i] - heights[i-1]);
        if (i > 1) cur = min(cur, prev2 + abs(heights[i] - heights[i-2]));
        prev2 = prev;
        prev = cur;
    }

    return prev;
}

int main() {
    int n; cin>>n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin>>heights[i];
    cout<<Solution(n, heights)<<"\n";
    return 0;
}