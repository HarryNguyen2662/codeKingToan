#include <bits/stdc++.h>
using namespace std;
pair<long long, int > mw[300005];
long long mn[300005],sum[300005];
int n,k;
bool check(long long m)
{
    mn[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        long long kk = sum[i] - i*m;
        mn[i]= min(mn[i-1], kk);
       // cout << mn[i]<<" "<<kk<<endl;
        if (i>=k&&kk-mn[i-k]>=0) return true;   
    }
    return false;
}
int main()
{
    //freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long luu1, luu2;
    int x;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        sum[i] = sum[i-1] + x;
    }
    long long l = 0 , r = 3e11;
    while (l<=r)
    {
        long long mid = (r + l)/2;
        if (check(mid)) l = mid + 1; else r = mid - 1;
    }
   // cout << r << endl;
    double ans =0;
    mw[0] = {0,0};
    for (int i = 1; i <= n; i++)
    {
        long long kk = sum[i] - i*r;
        if (mw[i-1].first > kk)
        {
            mw[i]={kk,i};
        }
        else
        {
            mw[i] = mw[i-1];
        }
        if (i>=k && kk-mw[i-k].first>=0)
        {
            double ldk =(sum[i]-sum[mw[i-k].second]), un = (i-mw[i-k].second);
            if (ans < ldk/un)
            {
                ans = ldk/un;
                luu1 = (sum[i]-sum[mw[i-k].second]);
                luu2 = (i-mw[i-k].second);
            }
        }   
    }
    cout << luu1/luu2<<".";
    for (int i = 1; i<= 5; i++)
    {
        luu1 = (luu1%luu2)*10;
        cout << luu1/luu2; 
    }
    luu1 = (luu1%luu2)*10;
    int u = luu1/luu2;
    luu1 = (luu1%luu2)*10;
    if (luu1/luu2>5) cout << u + 1; else cout << u;
}
