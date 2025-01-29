//Problem Link - https://www.geeksforgeeks.org/batch/competitive-programming/track/cp-math-bitMasking/problem/interesting-ternary-numeral-system

/*
Problem Statement -

Given a string s, which denotes a decimal number in its respective ternary representation. 
there are three kinds of bits in ternary representation -> 0, 1, 2.

Now, we want to change the ternary representation in form of 'z', 'p' & 'n'.
where, 'z' -> 0, 'p' -> 1, 'n' -> -1

Our task is to convert the original ternary number to the custom ternary representation.

Example - 
s = 102
o/p = ppn

s = 22
o/p = pzn
*/

#include <bits/stdc++.h>
using namespace std;

char Rules (char x, char& c) {
    // zz, zp, zn, pz, pp, pn
    char res = 'z';
    
    if (x == 'z') {
        if (c == 'z') 
            res = 'z';
        
        else
            res = 'p', c = 'z';
    }
    
    else if (x == 'p') {
        if (c == 'z') 
            res = 'p';
        
        else
            res = 'n', c = 'p';
    }
    
    else if (x == 'n') {
        if (c == 'z')
            res = 'n';
        
        else 
            res = 'z', c = 'z';
    }
    
    return res;
}

string Solve(string n) {
    unordered_map<int, int> mp;
    char c = 'c';
    mp['0'] = 'z', mp['1'] = 'p', mp['2'] = 'n', mp['c'] = 'z';
    
    int sz = n.size();
    string res;
    if (mp[n[sz-1]] == 'n') {
        res.push_back('n');
        mp['c'] = 'p';
    }
    
    else {
        res.push_back(mp[n[sz-1]]);
    }
    
    for (int i = sz-2; i >= 0; i--) {
        char carry = mp[c];
        int val = Rules(mp[n[i]], carry);
        res.push_back(val);
        mp[c] = carry;
        if (n[i] == '2') mp[c] = 'p';
    }
    
    if (mp[c] == 'p') res.push_back(mp[c]);
    
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t; cin>>t;
    while (t--) {
        string tern; cin>>tern;
        cout<<Solve(tern)<<"\n";
    }
    
    return 0;
}

// Time Complexity : O(size of string)
// Space Complexity : O(1)