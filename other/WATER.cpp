#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 20
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1 << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 1e5;
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo18 = 1e18;
const long long oo15= 1e15;
int rmq[2000005][log+1];
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
    int n, m;
    cin >> n >> m; 
    for(int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r; //cout << l << " " << r << endl;
        if (r < l) 
        {
            rmq[1][0] = max(rmq[1][0], r+1);
            //cout << "cehc " << rmq[1][0] << endl;
            r += n;
        }
            rmq[l][0] = max(rmq[l][0], r+1);
            rmq[l+n][0] = max(rmq[l+n][0], r+n+1); 
    } 

    for (int i = 1; i <= 2*n-1; i ++)
    {
        rmq[i][0] = max(rmq[i-1][0], rmq[i][0]);
        //cout << rmq[i][0] << endl;
        if (i <= n)
        {
            if (rmq[i][0] <= i)
            {
                //cout << i << endl;
                cout << -1; return 0;
            }
        }
        if (rmq[i][0] > 2*n) rmq[i][0] = 2*n;
    }

    rmq[2*n][0] = 2*n;
    for (int i = 1; i <= log ; i++)
        for (int j = 1; j <= 2*n; j++)
            rmq[j][i] = rmq[rmq[j][i-1]][i-1];
    int res = oo;
    for (int i = 1; i <= n; i++)
    {
        int l = i;
        int day = 0;
        for (int j = log; j >= 0; j--)
            if (rmq[l][j] <= i+n-1)
            {
                //cout << l << endl;
                l = rmq[l][j];
                day += mask(j);
            }
        res = min(res, day);
    }

    cout << m - res - 1;
}