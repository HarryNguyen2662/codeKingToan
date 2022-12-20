#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 19
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
const long long oo18 = 1e18;
int matchx[1005], matchy[1005], dist[1005];
vector<int> eg[1005];
vector<int> ldk;
pair<int,int> a[1000005];
bool kt[2000010];
int n;
void solve()
{
    if (n%2) n--;
    cout <<n/2<<"\n";
    int p = n;
    while (n > 0)
    {
        while(kt[n + p]) p--;
        for (int i = 1; i <= (n-p+1)/2; i++)
            cout << a[n-i+1].se <<" "<<a[p+i-1].se<<"\n";
        n = p-1; 
        p =n-1;
    }
}
bool bfs()
{
    bool check= false;
    queue<int> q;
    for (auto v : ldk)
        if (matchy[v]==0)
        {
            dist[v] = 0;
            q.push(v);
        }
         else   dist[v] = oo;
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for (auto v : eg[u])
        if (matchx[v] == 0)
        {
            check = true;
        }
        else if (dist[matchx[v]] == oo) {
            dist[matchx[v]] = dist[u] + 1;
            q.push(matchx[v]);
        }
    }
    return check;
}
bool dfs(int u)
{
    if (dist[u] == oo) return false;
    for (auto v :eg[u])
    if(matchx[v] == 0||(dist[matchx[v]]==dist[u]+1&&dfs(matchx[v])))
    {
        matchx[v] = u;
        matchy[u] = v;
        return true;
    }
    return false;
}
void solve1()
{
    vector<int> cs1; vector<pair<int,int> > res;
    for (int i = n; i ; i--)
    {
        if (a[i].fi%2&&a[i].fi!=1) ldk.pb(i);
        else if (a[i].fi ==1) cs1.pb(i);
    }
    for (auto v: ldk)
    for (int i = n; i ; i--) 
    {
        if (a[i].fi%2==0&&kt[a[v].fi + a[i].fi]==0) eg[v].pb(i);
    }
    for (auto v: cs1)
    for (int i = n; i ; i--) 
    {
        if (a[i].fi%2==0&&kt[a[v].fi + a[i].fi]==0) eg[v].pb(i);
    }
    int dem = 0,ddem = 0;
    while (bfs())
    {
        for(auto v : ldk) if(matchy[v] == 0) dem += dfs(v);
    }
    for (auto v: ldk) if (matchy[v]) res.pb({v,matchy[v]});
    memset(matchx, 0 , sizeof matchx); memset(matchy, 0, sizeof matchy);
    for (auto v : cs1) ldk.push_back(v);

    while (bfs())
    {
        for(auto v : ldk) if(matchy[v] == 0) ddem += dfs(v);
    }
    int sl1 = cs1.size() -(ddem-dem);
    if (ddem +sl1/2 > dem+ cs1.size()/2)
    {
        if (sl1%2) sl1--;
        cout << sl1/2+ddem<<"\n";
        for (auto v : ldk) if (matchy[v]) cout<<a[v].se<<" "<<a[matchy[v]].se<<"\n";
        for (auto v : cs1)
        if (!matchy[v])
        {
            if (sl1 == 0 )break;
            if (sl1%2 == 0) cout << a[v].se<<" "; else cout << a[v].se<<"\n";
            sl1--;
        }  
    }
    else
    {
        cout << dem+cs1.size()/2<<"\n";
        for (auto v : res) cout << a[v.fi].se <<" "<<a[v.se].se<<"\n";
        for (int i = 1; i < cs1.size(); i+=2) cout<<a[cs1[i-1]].se<<" "<<a[cs1[i]].se<<"\n";
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int> > res;
    kt[1] = 1;
    for (int i = 2; 1ll*i*i <= 2e6+5; i++)
        if (kt[i] == 0)
            for (int j = i*i; j <= 2e6+5; j+= i) kt[j] = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    } 
    sort(a+1,a+n+1);
    bool ktt = false;
    for (int i = 2; i <=n ;i ++) if(a[i].fi == a[i-1].fi)
    {
        ktt = true; 
        break;
    }
    if (ktt) solve1(); else solve();   
}