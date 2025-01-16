//Task is to transform gray code to binary number

#include <bits/stdc++.h>
using namespace std;

int Solve(int n) {
    //TC = O(no.of bits)

    int res = 0;

    while (n) {
        res ^= n;
        n >>= 1;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n; cin>>n;
        cout<<Solve(n)<<"\n";
    }

    return 0;
}