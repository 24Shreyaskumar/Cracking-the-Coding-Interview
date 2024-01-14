#include <bits/stdc++.h>
using namespace std;

string Solution(int a, int b, int c) {
    c = c & 1;
    return c ? a+1 > b ? "First" : "Second" : a > b+1 ? "First" : "Second";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while (t--) {
        int a, b, c;
        cin>>a>>b>>c;

        cout<<Solution(a, b, c)<<"\n";
    }

    return 0;
}