#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 5e4;

vector<int> adj[N + 5];
int e[N + 5];

void solve() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> e[i];

	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}