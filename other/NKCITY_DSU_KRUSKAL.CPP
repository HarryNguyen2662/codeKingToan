#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> cap;
const long long MOD = 1e9 + 7;
const long long oo = 1e15;
int par[1105];
int find_par(int u) {
    while(par[u] > 0) u = par[u];
    return u;
}
bool merge(int u, int v) {
    u = find_par(u); v = find_par(v);
    if(u == v) return false;
    
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u,v,m,gt,n;
    cin >>n >> m;
    vector<pair<int, cap> > ldk;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> gt;
        ldk.push_back({gt,{u,v}});
    }
    memset(par, -1, sizeof par);
    int ans =0;
    sort(ldk.begin(), ldk.end());
    for (auto v : ldk)
        if (merge(v.s.f, v.s.s))
        {
            ans = max(ans, v.f);
        }
    cout << ans;
}