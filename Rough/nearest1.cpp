#include <bits/stdc++.h>
using namespace std;

void Solve(int n, int m, vector<vector<int>>& mat) {
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, ans(n, vector<int>(m, -1));

    for (int i= 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j]) {
                ans[i][j] = 0;
                q.push({{i, j}, 0});
            }
        }
    }

    while (q.size()) {
        auto node = q.front().first;
        int row = node.first, col = node.second;
        int dist = q.front().second;
        q.pop();

        for (auto i : dirs) {
            int r = row + i[0];
            int c = col + i[1];

            if (r >= 0 && r < n && c >= 0 && c < m && ans[r][c] == -1) {
                ans[r][c] = dist + 1;
                q.push({{r, c}, ans[r][c]});
            } 
        }
    }

    for (auto i : ans) {
        for (auto j : i) {
            cout<<j<<" "; 
        }
        cout<<"\n";
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t; cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>mat[i][j];
            }
        }

        Solve(n, m, mat);
        cout<<"\n";
    }
}