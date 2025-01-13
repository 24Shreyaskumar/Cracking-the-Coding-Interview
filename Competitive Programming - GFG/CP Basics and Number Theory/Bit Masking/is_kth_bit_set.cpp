//Task is to check if the kth bit in binary form of n is set or not.

#include <bits/stdc++.h>
using namespace std;

string left_shift_method(int n, int k) {
    return (n & (1 << (k-1))) ? "Yes" : "No";
}

string right_shift_method(int n, int k) {
    return ((n >> (k-1)) & 1) ? "Yes" : "No";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int n, k;
        cin>>n>>k;
        cout<<left_shift_method(n,k)<<"\n";
    }

    return 0;
}