#include <bits/stdc++.h>
using namespace std;

bool Solve(int a, int b, unordered_map<int, vector<int>>& adj, unordered_map<int, pair<int, int>>& nodes) {
	if (a == b || nodes[a].second) {
		return true;
	}

	nodes[a].first = 1;

	bool flag = false;
	for (auto i : adj[a]) {
		if (nodes[i].first == 0) {
			bool t = Solve(i, b, adj, nodes);
			if (t) nodes[i].second = 1;
			flag |= t;
		}
	}

	return flag;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	unordered_map<int, pair<int, int>> nodes(n);

	for (int i = 0; i < n; i++) {
		int node; cin>>node;
		// cout<<node<<"\n";
		nodes[node] = {0, 0};
	}

	int e; cin>>e;

	unordered_map<int, vector<int>> adj;

	while (e--) {
		int p, q;
		cin>>p>>q;
		adj[p].push_back(q);
		adj[q].push_back(p);
	}

	// for (auto i : adj) {
	// 	cout<<i.first<<": \n";
	// 	for (auto j : i.second) cout<<j.second<<" "<<j.first<<"\n";
	// }

	int a, b;
	cin>>a>>b;

	unordered_map<int, pair<int, int>> nodes_cp = nodes;

	Solve(a, b, adj, nodes);
	Solve(b, a, adj, nodes_cp);

	set<int> res1, res2;

	for (auto i : adj[a]) {
		if (i == b) {
			res1.insert(a);
			continue;
		}

		if (nodes[i].second) res1.insert(i);
	}

	for (auto i : adj[b]) {
		if (i == a) {
			res2.insert(a);
			continue;
		}

		if (nodes_cp[i].second) res2.insert(i);
	}

	// for (auto i : res1) cout<<i<<" ";
	// cout<<", ";
	// for (auto i : res2) cout<<i<<" ";
	// cout<<"\n";
	
	if (res1.size() > res2.size()) res1 = res2;

	for (auto i : res1) cout<<i<<" ";
	cout<<endl;
	
	return 0;
}