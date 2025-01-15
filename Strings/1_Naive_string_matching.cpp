#include <bits/stdc++.h>
using namespace std;

int Solve(string& s, string& t) {
    int n = s.length(), m = t.length();

    for (int i = 0; i <= n-m; i++) {
        int k = i, j = 0;

        while (j < m) {
            if (s[k] != t[j]) break;
            k++, j++;
        }

        if (j == m) return i;
    }

    return -1;
}

int main(int argc, char**argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (argc < 3) return 1;
    string s = argv[1], t = argv[2];

    cout<<Solve(s, t)<<endl;
    return 0;
}