#include <bits/stdc++.h>
using namespace std;

bool isPal(int i, int j, string& s) {
    while (i <= j) {
        if (s[i] != s[j]) return false;
        i++, j--;
    }

    return true;
}

int Solve(string& s) {
    int n = s.size();
    vector<int> dp(n+1, 0);

    for (int i = n-1; i >= 0; i--) {
        int mn = 1e9;
        for (int j = i; j < n; j++) if (isPal(i, j, s)) mn = min(mn, dp[j+1] + 1);
        dp[i] = mn;
    }

    return dp[0] - 1;
}

int main() {
    int t; cin>>t;
    while (t--) {
        string s; cin>>s;
        cout<<Solve(s)<<"\n";
    }

    return 0;
}