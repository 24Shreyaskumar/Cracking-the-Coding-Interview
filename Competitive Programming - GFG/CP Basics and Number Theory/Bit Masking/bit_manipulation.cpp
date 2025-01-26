//Problem link -> https://www.geeksforgeeks.org/batch/competitive-programming/track/cp-math-bitMasking/problem/bit-manipulationx

/*
Problem Statement - 
Given an integer N, our task is to find the minimum number of rounds required to convert its binary representation to zero using the following rules -

Rule 1 - 
    if (i+1)th bit is ON and all other bits to the right are OFF, then, change ith bit.

Rule 2 -
    change the rightmost bit.
    Note - rightmost bit = least significant bit.

Difficulty - Medium
Note - This problem is a variation of Gray Code to Binary number conversion.
*/

#include <bits/stdc++.h>
using namespace std;

int Solve(int n) {
    //Algo is same as Gray code to binary code conversion.
    int res = n;
    while (n) {
        n >>= 1;
        res ^= n;
    }
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