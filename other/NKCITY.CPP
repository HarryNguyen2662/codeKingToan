#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> cap;
const long long MOD = 1e9 + 7;
const long long oo = 1e15;
long long d[1105];
int n;
vector<cap> a[1105];
long long prim(int w)
{
    for (int i = 1; i <= n; i++) d[i] = oo;
    priority_queue<cap, vector<cap>, greater<cap> > pr;
    long long sum = 0;
    d[w] = 0;
    pr.push({d[w], w});
    while (!pr.empty())
    {
        int  du = pr.top().f;
        int  u = pr.top().s;
        pr.pop();
        if (du != d[u]) continue;
        sum=max(sum, d[u]); //cout << u << endl;
        d[u]= 0;
        for (auto e : a[u])
        {
            int v = e.f;
            int dd = e.s;
            if (d[v] > dd)
            {
                d[v] = dd;
                pr.push({d[v], v});
            }
        }
    }
    return sum;
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int u,v,m,gt;
    cin >>n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> gt;
        a[u].push_back({v, gt});
        a[v].push_back({u, gt});
    }
    cout << prim(1);
}