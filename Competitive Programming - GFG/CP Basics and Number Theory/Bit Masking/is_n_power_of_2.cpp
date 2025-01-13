//Task is to find the given number is a power of 2.

#include <bits/stdc++.h>
using namespace std;

string Solve(int n) {
    return (n & (n-1)) ? "No" : "Yes";
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