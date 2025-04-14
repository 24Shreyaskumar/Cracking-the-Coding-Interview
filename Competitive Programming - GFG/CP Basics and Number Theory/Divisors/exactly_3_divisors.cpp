#include <bits/stdc++.h>
using namespace std;

void Solve(int n) {
    // Note that only the squares of prime numbers in the range of 1 to N will have exactly 3 divisors.
    // So we only have to get the list of prime numbers in the range of sqrt(N).
    // We can make use of seive algorithm to find all the prime numbers in the above range.
    // Time Complexity: O(sqrt(n) * log(log(n)))
    // Space Complexity: O(n)

    vector<int> primes(n+1, 1);

    for (int i = 2; i * i <= n; i++) {
        if (primes[i] == 1) {
            cout<<(i * i)<<" ";
            for (int j = i * i; j <= n; j += i) primes[j] = 0;
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        Solve(n);
        cout<<endl;
    }

    return 0;
}