#include <bits/stdc++.h>
using namespace std;

// set<int> res;

int Solve(int a, int b, unordered_map<int, vector<int>>& adj, unordered_map<int, int>& nodes) {
	queue<int> q;
	q.push(a);

	while (q.size()) {
		int node = q.front();
		q.pop();

		if (node == b) return 1;
		nodes[node] = 1;

		for (auto i : adj[node]) {
			if (!nodes[i]) 
				q.push(i);
		}
	}

	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	unordered_map<int, int> nodes(n);

	for (int i = 0; i < n; i++) {
		int node; cin>>node;
		// cout<<node<<"\n";
		nodes[node] = 0;
	}

	int e; cin>>e;

	unordered_map<int, vector<int>> adj;

	while (e--) {
		int p, q;
		cin>>p>>q;
		adj[p].push_back(q);
	}

	// for (auto i : adj) {
	// 	cout<<i.first<<": \n";
	// 	for (auto j : i.second) cout<<j.second<<" "<<j.first<<"\n";
	// }

	int a, b;
	cin>>a>>b;

	cout<<Solve(a, b, adj, nodes)<<"\n";

	// for (auto node : res) cout<<node<<" ";
	// cout<<endl;

	return 0;
}