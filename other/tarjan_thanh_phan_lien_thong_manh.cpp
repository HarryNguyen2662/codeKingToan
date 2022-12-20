#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> cap;
const long long MOD = 1e9 + 7;
const long long oo = 1e9;
int cnt = 0;
int ans = 0;
vector<int > a[10105];
stack<int> st;
int low[10105], num[10105];

void tarjan(int u)
{
    low[u] = num[u] = ++cnt;
    st.push(u);

    for(auto v : a[u])
    if (num[v])
    {
        low[u] = min(low[u], num[v]);
    }
    else 
    {
        tarjan(v);
        low[u] = min(low[u], low[v]);
    }
    if (num[u] == low[u])
    {
        ans ++;
       // cout<<low[u]<<endl;
        while(true)
        {
            int v = st.top(); st.pop();
            low[v] = num[v] = oo;
            if (u == v) break;
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
    int n,m,u,v;
    cin >> n >> m;
    for(int i = 1 ; i <= m; i++)
    {
        cin >> u >> v;
        a[u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
        if (!num[i]) tarjan(i);
    cout << ans;
}