 #include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const long long MOD = 1e9 + 7;
const int oo = 1e9;
int num[1000],low[1000],dd[1000];
int slt= 0;
int cnt =0;
stack<int> st;
vector<int> a[1000];
void tarjan(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);
    for (auto v: a[u])
        if (num[v] >0 ) low[u] = min(low[u],num[v]);
        else if (num[v] == 0) 
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
    if (low[u] == num[u])
    {
        slt++;
        while(true)
        {
            int v = st.top(); st.pop();
            low[v]= oo;
            num[v] = -slt;
            if (v==u) break;
        }
    }
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
    int n ,m,u,v;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        a[u].pb(v);
    }
    for (int i = 1; i<= n; i++)
    if (num[i]==0) tarjan(i);
   // for (int i = 1; i<= n; i++)
     //   cout << num[i]<<" ";
    int ans = 0;
    for (int i = 1; i<= n; i++)
        for (auto j : a[i])
            if (num[i]!=num[j]) dd[-num[j]] = 1;
    for (int i = 1; i <= slt; i++) if (!dd[i]) ans ++;
    cout << ans; 
}