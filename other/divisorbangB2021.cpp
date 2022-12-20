#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
pair<int,int> a[26];
int n;
long long dp[1000005][26];
long long solve(int x, int i)
{
    if ( x <= 0) return 0;
    if (i == 0) return 1;
    if (x <= 1e6 && dp[x][i]!=-1) return dp[x][i];
    int dem = 0;
    int w = 1;
    long long ans = solve(x, i - 1); 
    if (a[i].se)
    while (w <= x/a[i].fi)
    {
        dem++;
        w = w*a[i].fi;
        ans += solve(x/w, i-1);
        if (dem == a[i].se) break;
    }
    if (x <= 1e6) return dp[x][i] = ans; else return ans;
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
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi >> a[i].se;
    }
    memset(dp, -1, sizeof dp);
    int testcase = 3;
    while(testcase--)
    {
        int l, r;
        cin >> l >> r;
        cout << solve(r, n) - solve(l-1, n)<<"\n";
    }
}