#include <bits/stdc++.h>
using namespace std;

int Solve(int a, int b, unordered_map<int, vector<pair<int, int>>>& adj, unordered_map<int, int>& nodes) {
	priority_queue<pair<int, int>> pq;
	pq.push({0, a});

	while (pq.size()) {
		auto node = pq.top().second;
		auto time = -1 * pq.top().first;
		pq.pop();

		nodes[node] = 1;
		// cout<<node<<", "<<time<<"\n";
		if (node == b)
			return time;

		for (auto edge : adj[node]) {
			if (!nodes[edge.second]) {
				pq.push({-1 * (time + edge.first), edge.second});
			}
		}

	}

	return -1;
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

	unordered_map<int, vector<pair<int,int>>> adj;

	while (e--) {
		int p, q, t;
		cin>>p>>q>>t;
		adj[p].push_back({t, q});
	}

	// for (auto i : adj) {
	// 	cout<<i.first<<": \n";
	// 	for (auto j : i.second) cout<<j.second<<" "<<j.first<<"\n";
	// }

	int a, b;
	cin>>a>>b;

	cout<<Solve(a, b, adj, nodes)<<"\n";

	return 0;
}