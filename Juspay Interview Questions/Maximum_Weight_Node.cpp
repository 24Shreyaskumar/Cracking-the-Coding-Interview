/*
Problem Description :- Maximum Weight Node
Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- the node number of maximum weight node(Weight of the node is the sum of node numbers of all nodes pointing to that node).

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-

The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.
OUTPUT FORMAT :

First line denotes the node number with maximum weight node.
Sample Input :
23
4 4 1 4 13 8 8 8 0 8 14 9. 15 11 -1 10 15 22 22 22 22 22 21

Sample Output :
22
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

int Solve(int n, vi& edges) {
    int mx = 0, mx_node = -1;
    vi res(n, 0);

    for (int i = 0; i < n; i++) {
        if (edges[i] != -1) {
            res[edges[i]] += i;
            if (mx < res[edges[i]]) {
                mx = res[edges[i]];
                mx_node = i;
            }
        }
    }

    if (mx < res[edges[n-1]]) {
        mx = res[edges[n-1]];
        mx_node = n-1;
    }

    return mx_node;
}

Bankai_Tensa_Zangetsu {
    Eat Sleep Repeat

    {
        input(n)
        vi edges(n);
        input_vector(edges, n)
        cout<<Solve(n, edges)<<nl;
    }

    return 0;
}