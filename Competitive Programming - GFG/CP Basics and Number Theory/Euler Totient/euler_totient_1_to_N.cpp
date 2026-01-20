#include <bits/stdc++.h>
using namespace std;

void Solve(int n)
{
    vector<int> et(n + 1);

    for (int i = 0; i <= n; i++)
        et[i] = i;

    for (int d = 2; d <= n; d++)
    {
        if (et[d] == d)
        {
            et[d] = d - 1;
            for (int j = 2 * d; j <= n; j += d)
                et[j] = (et[j] / d) * (d - 1);
        }
    }

    for (auto i : et)
        cout << i << " ";
    cout << "\n";

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
        int n;
        cin >> n;
        Solve(n);
    }

    return 0;
}