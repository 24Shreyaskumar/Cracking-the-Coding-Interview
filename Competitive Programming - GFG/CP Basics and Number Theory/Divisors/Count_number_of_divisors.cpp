#include <bits/stdc++.h>
using namespace std;

int Solve(int n) {
    //T.C = O(sqrt(n))
    //S.C = O(1)
    //Using the method of prime factorisation
    //N = p1^e1 * p2^e2 ... *pk^ek
    //Res = (e1+1) * (e2+1) * ... * (ek+1)

    int res = 1;

    for (int i = 2; i * i <= n; i++) {
        int count = 1;
        while (n % i == 0) count++, n /= i;
        res *= count;
    }

    if (n >= 2) res *= 2;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;

    while(t--) {
        int n; cin>>n;
        cout<<Solve(n)<<"\n";
    }

    return 0;
}