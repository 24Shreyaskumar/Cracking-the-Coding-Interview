#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        string ans = "No\n";
        if(n == 2) {
            cout<<ans;
            continue;
        }
        for (int i = 2; i <= sqrt(n); i++) {
            int x = log2(n) / log2(i);
            float y = log2(n) / log2(i);
            float check = y - x;
            if (check == 0.0) ans = "Yes\n"; 
        }

        cout<<ans;
    }

    return 0;
}