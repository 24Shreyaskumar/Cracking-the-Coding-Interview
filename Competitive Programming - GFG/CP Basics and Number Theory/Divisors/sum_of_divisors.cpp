#include <bits/stdc++.h>
using namespace std;

vector<int> seive_least_factors(int mx) {
    vector<int> q(mx+1, 0);

    for (int i = 2; i <= mx; i++) {
        if (q[i] == 0) {
            q[i] = i;
            for (int j = i*i; j <= mx; j += i) 
                q[j] = q[j] ? q[j] : i; 
        }
    }

    return q;
}

int query(int q, vector<int>& slf) {
    if (q == 1) return 1;

    int res = 1;

    while (q > 1) {
        int term = 1, sum = 1;
        int lf = slf[q];

        while (slf[q] == lf) {
            q /= lf;
            term *= lf;
            sum += term;
        }

        res *= sum;
    }

    return res;
}

void Solve(vector<int>& queries) {
    int mx = 0;
    for (auto i : queries) mx = max(mx, i);

    vector<int> slf = seive_least_factors(mx);

    for (auto q : queries)
        cout<<query(q, slf)<<" ";

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int q; cin>>q;
        vector<int> queries(q);
        for (int i = 0; i < q; i++) cin>>queries[i];
        Solve(queries);
        cout<<endl;
    }

    return 0;
}