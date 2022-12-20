#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> cap;
const long long MOD = 1e9 + 7;
const long long oo = 1e9;
int cha[100105];
cap ldk[1000050];
int gt[1000050],gtt[1000050];
int find(int u)
{
    while(cha[u] > 0 ) u = cha[u];
    return u;
}
bool merge(int u, int v)
{
    u = find(u); v = find(v);
    if(u == v) return false;
    if (cha[u] > cha[v]) swap(u, v);
    cha[u] +=cha[v];
    cha[v] = u;
    return true;
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
    int t;
    cin >>t ;
    while (t--)
    {
        int n,m,q;
        cin >> n >> m >> q;
        for (int i = 1; i <= m; i++)
        {
            cin >> ldk[i].f >> ldk[i].s >> gt[i];
        }
        while (q--)
        {
            int id, ss;
            for (int i = 1; i <= m; i++) gtt[i] = gt[i]; 
           // vector<int> gt2(gt);
            cin >> id;
            cin >> ss;
            for (int i = 1; i <= ss; i++)
            {
                int e,w;
                cin >> e >> w;
                gtt[e] = w;
            }
            memset(cha, - 1, sizeof cha);
            for (int i = 1; i <= m; i++) if (gtt[i] < gtt[id]) merge(ldk[i].f, ldk[i].s);
            if (merge(ldk[id].f,ldk[id].s)) cout <<"NO"<<endl; else cout <<"YES" << endl;
        }
    }
}