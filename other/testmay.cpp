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

int f[5000005];
ll ff[5000005], ff1[5000005], dem[1005];
int dd[1005][1005];

void solve() 
{
    for(int i = 1; i <= 1000; i++)
    {
     f[1] = 1%i; f[2] = 1%i;
     dd[f[1]][f[2]] = 1;

     int cnt = 2;

     for (int j = 3; j; j++)
     {
         f[j] = (f[j-1] + f[j - 2])%i;
         cnt++;

         if (dd[f[j-1]][f[j]]) break;

         dd[f[j-1]][f[j]] = j - 1;
     }

     cout << cnt - 1 - dd[f[cnt - 1]][f[cnt]] << "\n";

     for (; cnt >= 2; cnt--)
     {
         dd[f[cnt-1]][f[cnt]] = 0;
     }
    }
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
