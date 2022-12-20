//huydichepcode
#include<bits/stdc++.h>

typedef long long ll;
typedef float fl;

using namespace std;

const int BASE = 20060529;
const int MOD = 1e9 + 7;
const int MAXN = 1e6  + 5;


ll n,i,j,k,res,m,a,b,c,x,y,val,bit[MAXN];

ll power(ll a, ll b, ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void updatePoint(ll u, ll v) {
    ll idx = u;
    while (idx <= n) {
        bit[idx] *= v;
        bit[idx] %= MOD;
        idx += (idx & (-idx));
    }
}

void updateRange(ll l, ll r, ll v) {
    updatePoint(l, v);
    updatePoint(r + 1, power(v, MOD - 2, MOD));
}

ll get(ll u) {
    ll idx = u, ans = 1;
    while (idx > 0) {
        ans *= bit[idx];
        ans %= MOD;
        idx -= (idx & (-idx));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
//  freopen("input.txt","r", stdin);
//  freopen("output.txt","w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= MAXN ; i ++ ){
        bit[i] = 1;
    }
    for (int i = 1; i <= n ; i ++ ){
        int k;
        cin >> k ;
        if ( k == 1 ){
            int x;
            cin >> x ;
            cout << get( x ) << "\n";

        }
        else {
            int x, y;
            cin >> x >> y >> val;
            updateRange(x, y, val);
        }
    }
    return 0;
}