#include<bits/stdc++.h>
#define fir first
#define sec second

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

struct Edge {
    int u, v;
};

const int N = 1e5 + 5;
const int Bit = 19;
const int oo32 = 1e9 + 1;
const ll oo64 = 1e18 + 1;
const pli oop = pli(-oo64, -oo32);

vector<pii> adj[N];
vector<Edge> List[N];
Edge E[N];
ll V[N * 4], LV[N * 4], LH[N * 4], Dp[N], Sum[N];
pli H[N * 4];
int Id1[N], Id2[N], P[N][Bit], Depth[N];
int n, m, cnt;
ll k;

void Dfs(int fa, int u) {
    Depth[u] = Depth[fa] + 1;
    P[u][0] = fa;
    Id1[u] = ++cnt;

    for (pii v : adj[u])
        if (v.fir != fa)
            Dfs(u, v.fir);

    Id2[u] = cnt;
}

int getLca(int u, int v) {
    if (Depth[u] < Depth[v])
        swap(u, v);

    int log = log2(Depth[u]);

    for (int j = log; j >= 0; j--)
        if (Depth[u] - (1 << j) >= Depth[v])
            u = P[u][j];

    if (u == v) return (u);

    for (int j = log; j >= 0; j--)
        if (P[u][j] != P[v][j]) {
            u = P[u][j];
            v = P[v][j];
        }

    return (P[u][0]);
}

void buildV(int id = 1, int l = 1, int r = n) {
    if (l > r) return;

    if (l == r) {
        V[id] = 0;
        LV[id] = 0;
        return;
    }

    int mid = (l + r) / 2;

    buildV(id * 2, l, mid);
    buildV(id * 2 + 1, mid + 1, r);
    V[id] = min(V[id * 2], V[id * 2 + 1]);
}

void downV(int id) {
    ll v = LV[id];
    LV[id] = 0;

    V[id * 2] += v;
    LV[id * 2] += v;

    V[id * 2 + 1] += v;
    LV[id * 2 + 1] += v;
}

void updV(int u, int v, ll add, int id = 1, int l = 1, int r = n) {
    if (l > r) return;

    if (l > v || r < u) return;

    if (l >= u && r <= v) {
        V[id] += add;
        LV[id] += add;
        return;
    }

    downV(id);

    int mid = (l + r) / 2;

    updV(u, v, add, id * 2, l, mid);
    updV(u, v, add, id * 2 + 1, mid + 1, r);
    V[id] = min(V[id * 2], V[id * 2 + 1]);
}

ll getV(int u, int v, int id = 1, int l = 1, int r = n) {
    if (l > r) return (oo64);

    if (l > v || r < u) return (oo64);

    if (l >= u && r <= v)
        return (V[id]);

    downV(id);

    int mid = (l + r) / 2;

    return (min(getV(u, v, id * 2, l, mid), getV(u, v, id * 2 + 1, mid + 1, r)));
}

void buildH(int id = 1, int l = 1, int r = n) {
    if (l > r) return;

    if (l == r) {
        H[id] = pli(0, l);
        LH[id] = 0;
        return;
    }

    int mid = (l + r) / 2;

    buildH(id * 2, l, mid);
    buildH(id * 2 + 1, mid + 1, r);
    H[id] = max(H[id * 2], H[id * 2 + 1]);
}

void downH(int id) {
    ll v = LH[id];
    LH[id] = 0;

    H[id * 2].fir += v;
    LH[id * 2] += v;

    H[id * 2 + 1].fir += v;
    LH[id * 2 + 1] += v;
}

void updH(int u, int v, ll add, int id = 1, int l = 1, int r = n) {
    if (l > r) return;

    if (l > v || r < u) return;

    if (l >= u && r <= v) {
        H[id].fir += add;
        LH[id] += add;
        return;
    }

    downH(id);

    int mid = (l + r) / 2;

    updH(u, v, add, id * 2, l, mid);
    updH(u, v, add, id * 2 + 1, mid + 1, r);
    H[id] = max(H[id * 2], H[id * 2 + 1]);
}

pli getH(int u, int v, int id = 1, int l = 1, int r = n) {
    if (l > r) return (oop);

    if (l > v || r < u) return (oop);

    if (l >= u && r <= v)
        return (H[id]);

    downH(id);

    int mid = (l + r) / 2;

    return (max(getH(u, v, id * 2, l, mid), getH(u, v, id * 2 + 1, mid + 1, r)));
}

void DpDfs(int fa, int u) {
    for (pii v : adj[u])
        if (v.fir != fa)
            DpDfs(u, v.fir);

    Sum[u] = 0;

    for (pii v : adj[u])
        if (v.fir != fa) {
            Sum[u] += Dp[v.fir];
            updH(Id1[v.fir], Id2[v.fir], 1ll * v.sec);
        }

    pli x = getH(Id1[u] + 1, Id2[u]);

    while (x.fir > k) {
        //cout << u << ' ' << x.fir << ' ' << x.sec << '\n';
        int id = x.sec;

        updH(id, id, -oo64);
        updV(id, id, oo64);

        x = getH(Id1[u] + 1, Id2[u]);
    }

    Dp[u] = getV(Id1[u], Id2[u]) + 1;

    for (Edge e : List[u]) {
        //cout << u << ' ' << e.u << ' ' << e.v << '\n';
        Dp[u] = min(Dp[u], getV(Id1[e.u], Id1[e.u]) + getV(Id1[e.v], Id1[e.v]) + 1);
    }

    Dp[u] += Sum[u];

    //cout << "DpDfs" << ' ' << u << ' ' << Sum[u] << ' ' << getV(Id1[u], Id2[u]) << '\n';

    updV(Id1[u], Id2[u], Sum[u] - Dp[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back(pii(v, w));
        adj[v].push_back(pii(u, w));
    }

    for (int i = 1; i <= m; i++)
        cin >> E[i].u >> E[i].v;

    cnt = 0;
    Depth[0] = -1;
    Dfs(0, 1);

    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            P[i][j] = P[P[i][j - 1]][j - 1];

    for (int i = 1; i <= m; i++) {
        int u = E[i].u, v = E[i].v;
        int Lca = getLca(u, v);

        List[Lca].push_back(E[i]);
    }

    buildV();
    buildH();

    //cout << '\n';

    //for (int i = 1; i <= n; i++)
    //  cout << i << ' ' << Id1[i] << ' ' << Id2[i] << '\n';

    //cout << '\n';

    DpDfs(0, 1);

    //for (int i = 1; i <= n; i++) cout << Dp[i] << ' ';

    cout << Dp[1];
    return 0;
}