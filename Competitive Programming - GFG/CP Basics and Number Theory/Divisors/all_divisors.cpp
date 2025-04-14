// Print all the divisors of a number N in a sorted fashion.

#include <bits/stdc++.h>
using namespace std;

void Solve(int n) {
    cout<<1<<" ";
    int i = 2;

    //print the divisors less than sqrt of n
    for (; i*i <= n; i++) {
        if (!(n % i)) cout<<i<<" ";
    }

    i--;
    
    //print the numbers greater than sqrt of n
    for (; i >= 1; i--) {
        if (!(n % i) and ((n / i) != i)) cout<<(n / i)<<" ";
    }

    cout<<endl;
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        Solve(n);
    }

    return 0;
}