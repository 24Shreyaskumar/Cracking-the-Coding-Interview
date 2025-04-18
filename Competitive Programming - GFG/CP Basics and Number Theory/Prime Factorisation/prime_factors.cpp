// For a given number, find all the prime numbers of the number.

#include <bits/stdc++.h>
using namespace std;

vector<int> seive_least_factors(int n) {
    vector<int> slf(n+1, 1);

    for (int i = 2; i*i <=n; i++) {
        if (slf[i] == 1) {
            slf[i] = i;
            for (int j = i*i; j <= n; j += i)
                slf[j] = slf[j] == 1 ? i : slf[j];
        }
    }

    return slf;
}

void Solve(int n, vector<int>& slf) {
    while (n > 1) {
        int lf = slf[n];
        cout<<lf<<" ";
        n /= lf;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    vector<int> nums(t);

    int mx = 1;
    for (int i = 0; i < t; i++) {
        cin>>nums[i];
        mx = max(mx, nums[i]);
    }

    vector<int> slf = seive_least_factors(mx);

    for (int i = 0; i < t; i++) {
        Solve(nums[i], slf);
        cout<<endl;
    }

    return 0;
}