//Task is to provide a gray code equivalent of a binary number

#include <bits/stdc++.h>
using namespace std;

int Solve(int n) {
    //gray code can be obtained by performing xor on adjacent bits. the MSB remains same.
    //TC - O(1), SC - O(1)
    return n ^ (n >> 1);
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