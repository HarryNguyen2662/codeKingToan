#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7; 
long long dp[100005][2];
int check[100005];
vector<int> a[100005];
void solve(int u)
{
    check[u] = 1;
    dp[u][1] = 1;
    dp[u][0] = 1;
    for (auto v : a[u])
    if (check[v]==0)
    {
        solve(v);
        dp[u][0] = dp[u][0]*((dp[v][0] + dp[v][1])%MOD)%MOD;
        dp[u][1] = dp[u][1]*dp[v][0]%MOD; 
    }
    //cout << u << " "<< dp[u][1]<<" "<<dp[u][0]<<endl;
}
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,x,y;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    solve(1);
    cout << (dp[1][0]+dp[1][1])%MOD;
}