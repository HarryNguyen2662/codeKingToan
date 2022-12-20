#include<bits/stdc++.h>
using namespace std;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
int dd[505][505], a[505][505];
int n, m;
vector<pair<int, int> > ldk;

void dfs(int i, int j, int e)
{
    dd[i][j] = 1;
    for (int w = 0; w < 4; w++)
    {
        int ni = i + x[w], nj = j + y[w];
        if (ni < 1 || ni > m || nj < 1 || nj > n || abs(a[i][j]-a[ni][nj]) > e || dd[ni][nj]) continue;
        dfs(ni, nj, e);
    }
}
bool check(int e)
{
    memset(dd, 0, sizeof dd);
    dfs(1,1,e);
    for (auto v : ldk) if (!dd[v.first][v.second]) return false;
    return true;
}
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i<= m; i++)
        for (int j = 1; j<= n; j++)
        {
            cin >> a[i][j];
        }
    int xx;
    for (int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
        {
            cin >> xx;
            if(xx) ldk.push_back({i,j});
        }
    int l = 0, r = 1e9;
    while(l <= r)
    {
        int mid = (l + r)/2;
        if(check(mid)) r = mid - 1; else l = mid + 1;
    }
    cout << l;
}
