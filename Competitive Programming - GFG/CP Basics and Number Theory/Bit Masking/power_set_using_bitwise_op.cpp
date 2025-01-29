/*
We need to find the power set of a given string using bitwise operators.
E.g.

s = "abc"
power set -> {"", "a", "b", "c", "ab", "bc", "ac", "abc"}.alignas

Note that the order doesn't matter.
*/

#include <bits/stdc++.h>
using namespace std;

void Solve(string& s) {
    int n = s.size();
    int setsz = pow(2, n);
    cout<<"";

    for (int i = 0; i < setsz; i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) cout<<s[j];
        }
        cout<<", ";
    }

    cout<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        string s; cin>>s;
        Solve(s);
    }

    return 0;
}