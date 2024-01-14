#include <bits/stdc++.h>
#define MOD (int) (1e9 + 7)
using namespace std;

int Solve(long long n) {
    if (n == 0 || n == 1) return 1;
    long long p = 1, p2p = 1, cur = 0;
    for (long long i = 2; i <= n; i++) {
        cur = (((p) % MOD) + (p2p % MOD)) % MOD;
        p2p = p;
        p = cur;
    }
    return p;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        long long n; cin>>n;
        cout<<Solve(n)<<"\n";
    }

    return 0;
}