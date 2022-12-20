#include <bits/stdc++.h>                                                                                                                                                                                                                                                                                           //Created by LogN
using namespace std;
#define int long long
void _time() {
    #ifndef ONLINE_JUDGE
        // cout << "_\nTime : " << (int)clock() << "ms.\n";
    #endif
}
void fast() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("ab.inp", "r", stdin);
        freopen("ab.out", "w", stdout);
    #endif
}

const int N = 1e5+5;
int n, par[N], a[N];
vector<int> adj[N];

int ans[N];
void dfs(int u) {
    for (int v: adj[u]) {
        int p = u, cnt = 1;
        while (a[p] > a[v]) {
            ++cnt;
            p = par[p];
        }
        ans[v] = ans[p] + a[v] * cnt;
        dfs(v);
    }
}

int res;
void dfs(int u, int last, int mi) {
    res += mi;
    for (int v: adj[u]) if (v != last){
        dfs(v, u, min(mi, a[v]));
    }
}
bool solve() {
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        cin >> par[i];
        adj[par[i]].push_back(i);
        adj[i].push_back(par[i]);
    }
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i <= n; ++i) {
        res = 0;
        dfs(i, 0, a[i]);
        cout << res << ' ';
    }
    return 0;
}
signed main() {
    fast();
    int T = 1;
    // cin >> T;
    for (int i = 1; i <= T; ++i) {
        // cout << "Case " << i << ": ";
        if (solve()) {
            cout << "[Err case : " << i << "]";
            break;
        }
        cout << '\n';
    }
    //system("pause");
    return _time(), 0;
}       