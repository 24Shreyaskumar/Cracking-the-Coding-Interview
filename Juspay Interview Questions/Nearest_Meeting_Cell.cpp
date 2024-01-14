/*
Problem Description :- Nearest Meeting Cell
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (i.e. entry/exit points are unidirectional doors like valves). The cells are named with an integer from 0 to N-1.

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- Nearest meeting cell : Given any two cells - C1, C2, find the closest cell Cm that can be reached from both C1 and C2.

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have an exit.
Third line for each testcase contains two cell numbers whose nearest meeting cell needs to be found. (return -1 if there is no meeting cell from tw.
OUTPUT FORMAT :
1.Output a single line that denotes the nearest meeting cell (NMC).

Sample Input :
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
9 2

Sample Output :
4
*/

#include <bits/stdc++.h>
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORD(i, m, n) for(int i = m; i >= n; i--)
#define fe(i, ds) for(auto i : ds)
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define omap map<int, int>
#define umap unordered_map<int, int>
#define pb push_back
#define ppb pop_back
#define SORT(ds) sort(ds.begin(), ds.end());
#define all(ds) ds.begin(), ds.end()
#define Eat ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define Sleep int t; cin>>t;
#define Repeat while(t--)
#define input(n) int n; cin>>n;
#define input_str(s) string s; cin>>s;
#define input_vector(v, n) FOR(i, 0, n) cin>>v[i];
#define input_2dvector(v, m, n) FOR(i, 0, m) FOR(j, 0, n) cin>>v[i][j];
#define sz(n, ds) int n = ds.size();
#define Bankai_Tensa_Zangetsu int32_t main()
#define mod ((int) 1e9 + 7)
#define nl "\n"
#define newline cout<<nl;

using namespace std;

vi calculate_distance(int c1, vi& edges) {
    sz(n, edges);
    vi dist(n, -1);
    queue<pair<int, int>> q;
    q.push({c1, 0});

    while (q.size()) {
        int node = q.front().first;
        int d = q.front().second;
        q.pop();

        if (edges[node] != -1 && dist[edges[node]] == -1) {
            dist[edges[node]] = d+1;
            q.push({edges[node], d+1});
        }
    }

    return dist;
}

int Solve(int n, int c1, int c2, vi& edges) {
    int nearest_meeting_cell = -1;
    int dist = INT_MAX;

    vi dist_c1 = calculate_distance(c1, edges);
    vi dist_c2 = calculate_distance(c2, edges);

    // for (int i = 0; i < n; i++) {
    //     cout<<i<<", "<<dist_c1[i]<<", "<<dist_c2[i]<<"\n";
    // } 

    FOR (i, 0, n) {
        if (dist_c1[i] == -1 || dist_c2[i] == -1) continue;
        if (dist > dist_c1[i] + dist_c2[i]) {
            dist = dist_c1[i] + dist_c2[i];
            nearest_meeting_cell = i;
        }
    }

    return nearest_meeting_cell;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi edges(n);
        input_vector(edges, n)
        input(c1) input(c2)

        cout<<Solve(n, c1, c2, edges)<<nl;
    }

    return 0;
}