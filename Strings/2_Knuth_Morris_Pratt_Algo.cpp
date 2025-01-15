/*KMP Algorithm - optimised string matching algorithm*/

#include <bits/stdc++.h>
using namespace std;

vector<int> create_lps(string& t) {
    int m = t.size();
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        j = lps[i-1];

        while (j > 0 && t[i] != t[j])   
            j = lps[j-1];

        if (t[i] == t[j]) j++;
        lps[i] = j;
    }

    return lps;
}

int KMP(string& s, string& t) {
    vector<int> lps = create_lps(t);
    int n = s.size(), m = t.size();

    int i = 0, j = 0;

    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }

        else {
            if (j > 0)
                j = lps[j-1];
            else
                i++;
        }
    }

    return j == m ? i-m : -1;
}

int main(int argc, char**argv) {
    if (argc < 3) return 1;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s = argv[1], t = argv[2];
    cout<<KMP(s, t)<<endl;

    return 0;
}

/*
          |
abbabbabb babba
    |
lps -> [0, 0, 1, 1, 2]
        |  



create lps 
  |
abcaaabdabc
          |
00011120123
*/