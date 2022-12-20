#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("TGCAN.INP","r",stdin);
     freopen("TGCAN.OUT","w",stdout);
     ios_base::sync_with_stdio(0);
     cin.tie(0); 
    int n,l,r,mid;
    long long ans =0,dem=0;
    cin >> n;
    for (int i = 1; i<= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1;i <n; i++)
    if (a[i]!=a[i+1])
    {
        dem++;
        if (dem>2) ans = ans + dem*(dem-1)*(dem-2)/6;
        if (dem>1)
        {
            l= i; r= n;
            while (l<=r)
            {
                mid= (l+r)/2;
                if (a[mid]>=2*a[i]) r=mid-1; else l =mid+1;
            }
            ans = ans + dem*(dem-1)/2*(r-dem);
        }
        dem=0;
    } else dem++;
    if (dem)
    {
        if (dem>1) ans = ans+(dem+1)*dem*(dem-1)/6;
        if (dem>0) ans = ans + dem*(dem+1)/2*(n-dem-1);
    }
    cout << ans;
}