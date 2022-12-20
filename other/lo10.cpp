#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i)) & 1)
#define setp(x) setprecision(x)
#define log 18


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;

void solve()
{
    cout << rng()%10;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}