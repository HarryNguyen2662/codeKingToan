#include<bits/stdc++.h>
using namespace std;
struct yeuemNHI
{
    int l,r,t;
    bool operator < (yeuemNHI other)
    {
        if (r == other.r) return l < other.l; else
        return r < other.r;
    }
}a[10005];
int dp[10005];
int main()
{
    // freopen("HOTEL.INP","r",stdin);
    // freopen("HOTEL.OUT","w",stdout);
        freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,ll,rr,mid,ttt;
    cin >>n; 
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].t;
    }
   // sort(a + 1, a + 1 + n);
    for (int i = 1; i<=n ;i++)
    {
        //cout <<a[i].l<<" "<<a[i].r<<" "<<a[i].t<<endl;
        // if (a[i].r==a[i-1].r&&a[i-1].l==a[i].l) 
        //     {
        //         dp[i]=dp[i-1];
        //         continue;
        //     }
        // if (a[i].r==a[i-1].r+1&&a[i-1].l+1==a[i].l)
        //     {
        //         dp[i]=dp[i-1];
        //         continue;
        //     }
      //  if (a[i].r==a[i].l) ttt = 2; else ttt = 0;
        ll = 1; rr = i - 1;
        while(ll <= rr)
        {
            mid=(ll+rr)/2;
            if (a[mid].r<=a[i].l) ll = mid + 1; else rr = mid -1;
        }
        dp[i] = max(dp[i-1],dp[rr]+a[i].t);
        cout <<rr<<" "<< dp[i]<<endl;
    }
    cout << dp[n];
}