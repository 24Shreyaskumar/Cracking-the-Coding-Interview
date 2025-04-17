/*
Santa gave Geek a number N and led him to his pile of infinite gifts where each gift had a number written on it. Geek could take those gifts but the conditions were:

1. He could take only those gifts that had a composite number written on them. Assume that for each number, there were infinite gifts that had it written on them i.e there were infinite gifts with 1 written on them, infinite gifts with 2 written on them and so on upto infinity.

2. Sum of numbers on the top of the gifts he took should exactly be equal to N.

Tell Geek the maximum possible number of gifts he could take or print -1 if he would have to return empty handed.

Input:

1. The first line of the input contains a single integer T denoting the number of test cases. The description of the T test cases follows.
2. The first line of each test case contains the integer N.

Output: For each test case, print the answer.
Constraints:
1. 1 ≤ T ≤ 105
2. 1 ≤ N ≤ 109
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// Check if prime
// True -> if prime
// False -> if composite
bool isPrime(int n) {
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Solve the problem
int Solve(int n) {
    return (n % 4) & 1 ? (n / 4) - 1 : n / 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // Input values
    int t; cin>>t;
    
    while (t--) {
        int n; cin>>n;
        int res = Solve(n);
        if (!res || (res == 1 && isPrime(n))) res = -1;
        cout<<res<<"\n";
    }

    return 0;
}