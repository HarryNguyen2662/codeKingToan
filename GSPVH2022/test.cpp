#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,int> b[20000];
int a[200000], aa[20000];

void solve() 
{
    int n, c, r;
    cin >> n >> c >> r;

    for (int i = 1; i < n; i++) 
    {
        cin >> a[i];
        aa[i] = a[i];
    }

    for (int i = 1; i <= c; i++) cin >> b[i].fi >> b[i].se;

    int res = 0, kq = 1;

    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        int ok = i;
        for (int j = 1; j < n; j++) a[j] = aa[j];
        for (int j = n; j >= i + 1; j--) a[j] = a[j-1]; a[i] = r;

        int cnt = n;
        for (int j = 1; j <= c; j++)
        {
            int id = b[j].fi;
            for (int e = b[j].fi; e <= b[j].se; e++)
            {
                if (a[e] > a[id]) id = e;
            }


            if (ok >= b[j].fi && ok <= b[j].se)
            {
                if (id != ok) break; 
                else
                {
                    ok -= (id - b[j].fi);
                    cur++;
                }
            }
            else if (ok > b[j].se)
            {
                ok -= (b[j].se - b[j].fi);
            }

            for (int e = id + 1; e <= cnt - (b[j].se - id); e++) a[e] = a[e + (b[j].se - id)];
            cnt -= (b[j].se - id);
            for (int e = b[j].fi; e <= cnt - (id - b[j].fi); e++) a[e] = a[e + (id - b[j].fi)];
            cnt -= (id - b[j].fi);
        }


        if (res < cur)
        {
            res = cur; kq = i; 
        }

    }

    cout << kq;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking1.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("tournament.inp","r",stdin); freopen("tournament.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
