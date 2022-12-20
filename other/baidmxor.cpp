#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 16
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353; 
const int MAXN = 2e5+2;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18;   
const long long oooo = 9223372036854775807;
int luu[log+5];
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int t = log+2; luu[t] = -1;
    vector<int> ldk, dk;
    for (int i = 0; i <= log; i++)
    {
        ldk.clear(); dk.clear();
        for (int j = 1; j <= n; j++) if (j&mask(i)) ldk.pb(j); else dk.pb(j);
        if ((int)ldk.size() == 0 || (int)dk.size() == 0) continue;
        cout << "? " << ldk.size() <<" "; for (auto v: ldk) cout <<v<<" ";
        cout << dk.size() <<" "; for (int j = 0; j+1 < dk.size(); j ++) cout << dk[j] <<" "; 
        cout << dk.back();
        cout << endl;
        cin >> luu[i]; if (luu[t] < luu[i]) t = i; 
    }
    ldk.clear(); dk.clear();
    for (int i = 1; i <= n; i++) if (i&mask(t)) ldk.pb(i); else dk.pb(i);
    int l = 1, r = ldk.size();
    while (l <= r)
    {
        int mid = (l + r)/2;
        cout << "? " << mid-l+1 <<" "; for (int i = l-1; i < mid; i ++) cout << ldk[i] <<" ";
        cout << dk.size() <<" "; for (int i = 0; i +1 <dk.size(); i++) cout << dk[i] << " "; 
        cout << dk.back() << endl;
        int res; cin >> res;
        if (res == luu[t]) r = mid-1; else l = mid + 1;
    }
    l = ldk[l-1];
    int j = l; for (int i = 0; i <= log; i++) if (luu[t] == luu[i]) j = j^mask(i);
    if (l > j) swap(l, j);
    cout << "! " << l <<" "<<j << endl;
}