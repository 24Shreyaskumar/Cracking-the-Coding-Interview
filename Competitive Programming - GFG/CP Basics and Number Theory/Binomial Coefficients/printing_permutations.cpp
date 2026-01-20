// Given a string, print all its permutations.

#include <bits/stdc++.h>
using namespace std;

void permute(int i, string &s)
{
    if (i == s.size() - 1)
    {
        cout << s << "\n";
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        swap(s[i], s[j]);
        permute(i + 1, s);
        swap(s[j], s[i]);
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        // int n; cin>>n;
        string s;
        cin >> s;
        permute(0, s);
        cout << "\n";
    }

    return 0;
}