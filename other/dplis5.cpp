#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
pair<int, long long> dp[100005];
pair<int,int> a[100005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
   // ios_base::sync_with_stdio(0);
    //in.a(0); cout.a(0);
    int n,l,r,mid;
    cin >> n ;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].s >> a[i].f;
    }
    sort(a + 1, a + 1 + n );
    for (int i = 1; i <= n; i++)
    {
        l=  1 ; r= i - 1;
        while(l <= r)
        {
            mid = (l + r)/2;
            if (a[mid].f<a[i].s) l = mid + 1; else  r = mid -1;
        }
        dp[i] = max(dp[i-1], {dp[r].f + 1, dp[r].s + a[i].f - a[i].s + 1});
         //cout << dp[i].f << " " << dp[i].s << endl;
    }
    cout << dp[n].f << " " << dp[n].s;
}