#include <bits/stdc++.h>
using namespace std;
int dem[505][505];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,ans = 1e9;
    cin >> n ;
    for (int i = 1 ; i <= n; i++)
        for (int j =1 ; j<= n; j++)
        {
            cin >> x;
            dem[i][j] = dem[i-1][j]+dem[i][j-1] -dem[i-1][j-1]+x; 
        }
    for (int i = 1; i <n ; i++)
        for (int j = 1; j< n; j++)
        {
            int t = min({dem[i][j],dem[n][j]-dem[i][j],
                dem[i][n]-dem[i][j],dem[n][n]-dem[i][j]-dem[n][j]+dem[i][j]-dem[i][n]+dem[i][j]});
            int tt = max({dem[i][j],dem[n][j]-dem[i][j],
                dem[i][n]-dem[i][j],dem[n][n]-dem[i][j]-dem[n][j]+dem[i][j]-dem[i][n]+dem[i][j]});
            ans = min (ans, tt-t); 
        }
    cout << ans;
}
 