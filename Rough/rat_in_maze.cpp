#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, int n, int m, vector<vector<int>>& mat, vector<vector<int>>& vis, vector<vector<int>>& dir, vector<string>& ans, string path) {
    if (row == n-1 && col == m-1) {
        ans.push_back(path);
        return;
    }

    string dirs = "DLRU";

    for (int i = 0; i < 4; i++) {
        int r = row + dir[i][0];
        int c = col + dir[i][1];

        if (r >= 0 && r < n && c >= 0 && c < m && mat[r][c] && !vis[r][c]) {
            vis[row][col] = 1;
            dfs(r, c, n, m, mat, vis, dir, ans, path + dirs[i]);
            vis[row][col] = 0;
        }
    }

    return;
}

void Solve(int n, int m, vector<vector<int>>& mat) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
    dfs(0, 0, n, m, mat, vis, dir, ans, "");

    sort(ans.begin(), ans.end());

    for (auto i : ans) cout<<i<<" ";
    cout<<"\n";
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
    }
}
