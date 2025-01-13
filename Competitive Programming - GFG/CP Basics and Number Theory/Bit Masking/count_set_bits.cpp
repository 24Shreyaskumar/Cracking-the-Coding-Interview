//Task -> Find the number of set bits in binary representation of a decimal number.

#include <bits/stdc++.h>
using namespace std;

//Method 1 -
int naive(int n) {
    //TC -> O(no. of bits)
    int count = 0;
    while (n) 
        count += n&1, n >>= 1;
    return count;
}

//Method 2 -
int brian_kerningam_algo(int n) {
    //TC -> O(no. of set bits)
    int count = 0;
    while (n)
        n = n & (n-1), count++;
    return count;
}

//Method 3 -
void precompute(int *table) {
    table[0] = 0;
    for (int i = 1; i < 256; i++)
        table[i] = (i&1) + table[i>>1];
    return;
}

int lookup_table_method(int n, int *table) {
    //TC -> O(1);
    int count = 0;

    //we divide the 32 bit integer into 4 chunks of 8 bits each -> 0xff = 255 = 11111111 (8 set bits)
    for (int i = 0; i < 4; i++)
        count += table[n&0xff], n >>= 8;

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    int table[256];
    precompute(table);

    while (t--) {
        int n; cin>>n;
        cout<<lookup_table_method(n, table)<<"\n";
    }

    return 0;
}