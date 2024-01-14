#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int m; cin>>m;
        int mx = 0;
        vector<vector<int>> M(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin>>M[i][0]>>M[i][1];
        }

        int q; cin>>q;
        vector<int> Q(q, 0);

        for (int i = 0; i < q; i++) {
            cin>>Q[i];
        }

        vector<int> ans(q, 0);
        for (auto i : M) {
            for (int id = 0; id < q; id++) {
                if (i[0] <= Q[id] && i[1] >= Q[id]) ans[id]++; 
            }
        }

        for (auto id : ans) cout<<id<<"\n";

        cout<<"\n";
    }

    return 0;
}