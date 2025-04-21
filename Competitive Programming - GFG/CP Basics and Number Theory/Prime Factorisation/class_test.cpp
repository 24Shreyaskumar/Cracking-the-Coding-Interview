//works well when constraints for N > 10^7

/*
Geek teaches maths in Geekland state university in which Q students have enrolled. Geek took a class test of all the students in which he asked them to find any number and their score would be the sum of all the elements in its prime factorisation.
Now Geek has to check the submissions of all Q students but he does not have so much time, so he asked your help as you are his only friend. You have to find the score of each student.
 

Input:
1. The first line of the input contains a single integer Q denoting number of students.
2. Next Q lines contains one integer N.
 

Output: For each student, print his score.
 

Constraints:
1. 1 ≤ Q ≤ 1000
2. 2 ≤ N ≤ 10^9
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll Solve(int n) {
    int res = 0;
    
    for (int i = 2; i*i <= n; i++) {
        int count = 0;
        while ((n % i == 0) && n > 1) {
            count++;
            n /= i;
        }
        res += (count * i);
    }
    
    if (n > 1) res += n;
    return res;
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