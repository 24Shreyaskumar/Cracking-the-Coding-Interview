/*Created by @shreyaskumar24*/

#include <bits/stdc++.h>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define ppi pair<int, int>
#define umap unordered_map
#define pb push_back
#define ppb pop_back
#define SORT(ds) sort(ds.begin(), ds.end());
#define all(ds) ds.begin(), ds.end()
#define FOR(i, m, n, inc) for(int i = m; i < n; i+=inc)
#define FORD(i, m, n, dec) for(int i = m; i >= n; i-=dec)
#define FREQ(mp, ds) for(auto i : ds) mp[i]++;
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_str(s) string s; cin>>s;
#define input_vector(v, n) FOR(i, 0, n, 1) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m, 1) FOR(j, 0, n, 1) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
#define nl "\n"
#define nline cout<<nl;
#define MOD (int)(1e9 + 7)
typedef long long ll;

using namespace std;

int countDigits(ll n) {
    /*TC = O(no. of digits), 
    SC = O(1)*/
    int count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

ll sumDigits(ll n) {
    /*TC = O(no. of digits),
    SC = O(1)*/
    ll sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int gcd(int a, int b) {
    /*
    TC = O(log(min(a, b)))
    SC = O(log(min(a, b))) (auxillary stack space)
    gcd(a, b) = gcd(b, remainder), where remainder = a%b
    */
    if (!b) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    /*
    TC = O(log(min(a, b)))
    SC = O(log(min(a, b))) (auxillary stack space)
    */
    return (a*b) / gcd(a,b);
}

bool isPrime(ll n) {
    /*
    TC = O(root(n))
    SC = O(1)
    */
    if (n%2 == 0 || n%3 == 0) return 0;
    for (int i = 5; i*i < n; i+=6) 
        if (n%i == 0 || n%(i+2) == 0) return 0;
    return 1;
}

void getPF(vi& pf, int& n, int i) {
    while (n%i == 0) {
        pf.pb(i);
        n /= i;
    }
    return;
}

vi primeFactors(int n) {
    /*
    TC = O(root(n)*log(n))
    SC = O(root(n)*log(n))
    */

    vi pf;

    getPF(pf, n, 2);
    getPF(pf, n, 3);

    for (int i = 5; i*i <= n; i+=6) {
        //all the numbers in this iteration will always be prime
        getPF(pf, n, i);
        getPF(pf, n, i+2);
    }

    if (n > 3) pf.pb(n);
    return pf;
}

vi divisors(int n) {
    /*
    TC = O(root(n))
    SC = O(n)
    */

    vi div;

    int i;
    for (i = 1; i*i < n; i++) 
        if (n%i == 0) div.pb(i);
    
    for (; i >= 1; i--) 
        if (n%i == 0) div.pb(n/i);

    return div;
}

vi sieve(int n) {
    /*
    Aim: get all prime numbers till the given number
    TC = O(n*log(log(n)))
    SC = O(n)
    */

    vi isprime(n+1, 1), primes;
    for (int i = 2; i*i <= n; i++) {
        if (isprime[i]) {
            primes.pb(i);
            
            FOR(j, i*i, n+1, i) isprime[j] = 0;
        }
    }

    return primes;
}

ll fib_logn(int n, umap<ll, ll>& dp) {
    /*
    Aim : to calculate nth fibonacci number
    Intution : 
        Fn = F(n/2) * (2 * F(n/2 + 1) - F(n/2)) -> n is even
           = F(n/2)^2 + F(n/2 + 1)^2            -> n is odd
    TC : O(logN)
    SC : O(logN) 
    */

    if (n == 0 || n == 1) return n;
    if (n == 2) return 1;
    if (dp[n]) return dp[n];

    ll nb2 = fib_logn(n/2, dp);
    ll nb2p1 = fib_logn(n/2 + 1, dp);

    dp[n] = (n & 1) ? ((nb2*nb2) % MOD + (nb2p1*nb2p1) % MOD) % MOD : \
                        (nb2 * ((2 * nb2p1) % MOD - nb2 + MOD)) % MOD;
    return dp[n];
}

ll fib_pisano(int n, int m) {
    /*
    Aim : to calculate nth fibonacci modulo m
    Intuition : we will use Pisano's period to calculate the mod.
    TC : O(m*m)
    SC : O(m*m)

    Note - The pisano's period is upper bounded by m*m.
    */

    vi pisano;
    pisano.pb(0); pisano.pb(1);
    int p = 1;

    FOR (i, 2, m*m, 1) {
        pisano[i] = (pisano[i-1] + pisano[i-2]) % m;
        if (!pisano[i] && pisano[i-1] == 1) {
            p = i;
            break;
        }
    }

    return pisano[n % p];
}

bool is_kth_bit_set(int n, int k) {
    /*
    Aim: to check if the kth bit in binary representation of n is set or not
    TC: O(1)
    SC: O(1)

    Logic: left shift the number 1 by k-1 bits and then use and operator on the given number\
     to check if its set or not.
    */
    return n & (1 << (k-1));
}

int Solve(int n, vi& nums) {
    int ans = 0;
    return ans;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi nums(n);
        input_vector(nums, n)

        cout<<Solve(n, nums)<<nl;
    }

    return 0;
}