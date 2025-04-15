/*
Geek's maths teacher wanted to teach her class of N children about factors of numbers so she gave them all a number each and told them to find out the sum of all factors of their number and they would get as many chocolates as the answer. Find out the total number of chocolates the teacher has to buy to be able to give all the children as promised.

Input:
1. The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
2. The first line of each test case contains the integer N, the number of children in the class.

3. The second line of each test case contains N space-separated integers, the i'th integer denoting the number given to the i'th student.

Output: For each test case, print the answer.

Constraints:
1. 1 ≤ T ≤ 103
2. 1 ≤ N ≤ 105
3. 1 ≤ a[ i ] ≤ 107
The sum of N overall test case does not exceed 10^6.
*/


#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> seive_least_factors(ll mx) {
    vector<ll> q(mx+1, 1);
    
    for (ll i = 2; i <= mx; i++) {
        if (q[i] == 1) {
            q[i] = i;
            for (ll j = i*i; j <= mx; j += i) 
                if (q[j] == 1) q[j] = i;
        }
    }
    
    return q;
}

ll query_solve(ll q, vector<ll>& slf) {
    if (q == 1) return 1;
    
    ll res = 1;
    
    while (q > 1) {
        ll term = 1, sum = 1, lf = slf[q];
        
        while (slf[q] == lf) {
            q /= lf;
            term *= lf;
            sum += term;
        }
        
        res *= sum;
    }
    
    return res;
} 

void Solve(vector<vector<ll>>& queries) {
    ll mx = 0;
    
    for (auto i : queries) 
        for (auto j : i) mx = max(mx, j);
    
    vector<ll> slf = seive_least_factors(mx);
    
    for (auto q1 : queries) {
        ll res = 0;
        
        for (auto q2 : q1)
            res += query_solve(q2, slf);
            
        cout<<res<<"\n";
    }
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    
    vector<vector<ll>> queries;
    
    while (t--) {
        ll q; cin>>q;
        vector<ll> querys(q);
        for (ll i = 0; i < q; i++) cin>>querys[i];
        queries.push_back(querys);
    }
    
    Solve(queries);
    
    return 0;
}