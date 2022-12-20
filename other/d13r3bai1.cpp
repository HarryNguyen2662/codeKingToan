#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

int n, m, k, a[1000005], b[1000005];    

bool check(int val)
{
    int dem = 0;
    int id = 1;

    for (int i = 1; i <= n; i++)
    {
        while(id < m && a[i] - b[id] > val) id++;
        if (id <= m && abs(a[i] - b[id]) <= val)
        {
            dem++; id++;
        }
        if (dem >= k) return true;
    }


    return false;
}

void solve() 
{
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    sort(a + 1, a + 1 + n); sort(b + 1, b + 1 + m);

    int l = 0, r = oo;

    while(l <= r)
    {
        int mid = (l + r)/2;
        if (check(mid)) r = mid - 1; else l = mid + 1;
    }

    cout << l;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
