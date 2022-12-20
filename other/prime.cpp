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
const int oo = 2e9;
int kt[1000001];
long long ssum[1000001], sum[1000001];
vector<int> prime;
int findx(int x)
{
    int l = 1, r = prime.size()-2;
    while(l<=r)
    {
      int mid = (l+r)/2;
      if (prime[mid]>= x) r = mid -1 ; else l = mid + 1;
    }
    return l;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    #else
    //online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 2; 1ll*i*i <= 1000000; i++)
      if (kt[i] == 0)
        for (int j = i*i; j <= 1000000; j+= i)
          kt[j] = 1;
    prime.pb(0);
    for (int i = 2; i <= 1000000; i++) if (kt[i] == 0) prime.pb(i);
    for (int i = prime.size()-1; i ; i--)
      {
          sum[i] = (sum[i+1] + prime[i])%MOD;
          ssum[i] = (ssum[i+1] + sum[i])%MOD;
      }
    prime.pb(oo);
    int t, l, r;
    cin >> t;
    while(t--)
    {
        cin >> l >> r;
        if (l > r) swap(l,r);
        l = findx(l);
        r = findx(r+1);
        //cout << l <<" "<< r << endl;                
        cout << ((ssum[l] - ssum[r] +MOD)%MOD - 1ll*(r-l)*sum[r]%MOD + MOD)%MOD<<"\n";
    }
}