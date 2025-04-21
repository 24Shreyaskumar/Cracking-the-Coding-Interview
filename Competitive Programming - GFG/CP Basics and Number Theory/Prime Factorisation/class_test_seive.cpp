//works well when constraints for N is 10^5, 10^6, but greater than that it is not the most optimised.

/*
Geek teaches maths in Geekland state university in which Q students have enrolled. Geek took a class test of all the students in which he asked them to find any number and their score would be the sum of all the elements in its prime factorisation.
Now Geek has to check the submissions of all Q students but he does not have so much time, so he asked your help as you are his only friend. You have to find the score of each student.
 

Input:
1. The first line of the input contains a single integer Q denoting number of students.
2. Next Q lines contains one integer N.
 

Output: For each student, print his score.
 

Constraints:
1. 1 ≤ Q ≤ 1000
2. 2 ≤ N ≤ 10^6
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> seive_least_factors(ll n) {
    vector<ll> slf(n+1, 1);
    
    for (ll i = 2; i*i <= n; i++) {
        if (slf[i] == 1) {
            slf[i] = i;
            for (ll j = i*i; j <= n; j += i)
                slf[j] = slf[j] == 1 ? i : slf[j];
        }
    }
    
    return slf;
}

ll Solve(ll n, vector<ll>& slf, unordered_map<ll, ll>& dp) {
    if (n == 1) return 0;
    
    ll res = 0;
    ll cp_n = n;
    
    while (n > 1) {
        if (dp[n]) return dp[cp_n] = res + dp[n];
        ll lf = slf[n]; 
        if (lf == 1) lf = n;
        res += lf;
        n /= lf;
    }
    
    return dp[cp_n] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    vector<ll> nums(t);
    
    ll mx = 1;
    for (ll i = 0; i < t; i++) {
        cin>>nums[i];
        mx = max(mx, nums[i]);
    }
    
    vector<ll> slf = seive_least_factors(mx);
    unordered_map<ll, ll> dp;
    
    for (ll i = 0; i < t; i++)
        cout<<Solve(nums[i], slf, dp)<<"\n";
        
    return 0;
}