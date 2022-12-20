#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 125250;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 9223372036854775807;
typedef pair<int,int> ii;
int d[100005];
vector<int> a[100005];
void solve()
{   
    int n;
    cin >> n;
    priority_queue<ii> q;
    for (int i = 1; i <= n; i++) 
    {
        cin >> d[i];
        q.push({d[i], i});
    }
    while (!q.empty())
    {
        int u = q.top().se;
        //cout << u << endl;
        int sl = q.top().fi;
        q.pop(); d[u] = 0;
        vector<int> luu;
        for(int i = 1; i <= sl; i++)
        {
            int v = q.top().se; q.pop();
            d[v]--;
            luu.pb(v);
            a[u].pb(v);
        }
        for (auto v : luu)
        if (d[v] != 0) q.push({d[v], v});
    }
    for (int i = 1; i <= n; i++) for (auto v : a[i]) cout << i << " " << v <<"\n";

}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    solve();
}
