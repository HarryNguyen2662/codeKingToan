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
    int n;
    int ans = 0;
    cin >> n;
    ans = 2;
    for (int i = 2; 1ll *i * i <= n; i++)
        if (n%i == 0)
        {
            ans += 4;
            if (1ll*i*i == n) ans-=2;
        }
    if (n%2 == 0) ans--; 
    cout << ans;
}