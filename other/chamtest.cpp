#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second
#define pb emplace_back
#define popb pop_back
#define pf emplace_front
#define popf pop_front

string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
ll mod = 998244353;
ll oo = 1e18;
ll s[100001][101];
ll a[100001];
void solve(){
   ll n, k;
   cin >> n >> k;
   for(ll i = 1 ; i <= n ; i ++){
       a[i] = -1;
       for(ll j = 1 ; j <= k ; j ++){
        int val;
           cin >> s[];
            a[i] = max(a[i], val - j + 1);
       }
   }
    sort(a + 1, a + 1 + n) ;
    ll res = a[1];
    for(ll i = 2 ; i <= n ; i ++){
        if(a[i] - k * (i - 1) >= res) res = a[i] - k * (i - 1);
    }
    cout << res;
}
 
int main (){
    ll t; 
    t=1;
    ios_base :: sync_with_stdio(0); cin.tie(0); cout.tie(0) ;
 // freopen("D.inp" , "r",stdin);
 // freopen("D.out" , "w",stdout);
    freopen("E:\\testne\\truelove\\test10.inp","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
   // cin >> t;
    while(t--){
        solve();
    }
}