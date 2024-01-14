/*
Problem Description :- Largest Sum Cycle
Given a maze with N cells. Each cell may have multiple entry points but not more than one exit(i.e entry/exit points are unidirectional doors like valves).

You are given an array Edge[] of N integers, where Edge[i] contains the cell number that can be reached from of cell i in one step. Edge[i] is -1 if the ith cell doesn’t have an exit.

The task is to find :- the sum of the largest sum cycle in the maze(Sum of a cycle is the sum of node number of all nodes in that cycle).

Note:- The cells are named with an integer value from 0 to N-1. If there is no node pointing to the ith node then weight of the ith node is zero.

INPUT FORMAT :-
The first line contains the number of cells N.
The second line has a list of N values of the edge[ ] array, where edge[i] conatins the cell number that can be reached from cell 'i' in one step. edge[i] is -1 if the ith doesn't have ans exit.

OUTPUT FORMAT :
First line denotes length of the largest cycle..
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

pair<int, int> dfs(int node, bool& isCycle, vi& vis1, vi& vis2, vi& edges) {
    vis1[node] = 1;
    pair<int, int> res = {0,0};

    if (edges[node] != -1 && !vis1[edges[node]]) 
        res = dfs(edges[node], isCycle, vis1, vis2, edges);

    if (vis2[node]) 
        isCycle = true;

    vis2[node] = 1;
    if (edges[node] != -1) vis2[edges[node]] = 1;

    if (!isCycle) res = {res.first + node, res.second+1};
    return res;
}

int Solve(int n, vi& edges) {
    vi vis1(n, 0), vis2(n, 0);
    pair<int,int> largestSumCycle = {0,0};
    
    for (int i = 0; i < n; i++) {
        if (i != -1 && !vis1[i]) {
            bool isCycle = false;
            pair<int, int> res = dfs(i, isCycle, vis1, vis2, edges);
            if (isCycle) largestSumCycle = max(largestSumCycle, res);
        }
    }

    return largestSumCycle.second ? largestSumCycle.second + 1 : 0;
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