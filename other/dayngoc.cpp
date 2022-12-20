#include<bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
long long pres[1000005];
int dem[1000005],a[1000005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k,dd,l;
    cin >> n>>k;
    l=1;
    pres[0] = 1;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
        if (!dem[a[i]]) dd++;
        dem[a[i]]++;
        while(dd>k)
        {
            dem[a[l]]--; if (!dem[a[l]])dd--;
            l++;
        }
        while(dem[a[l]]-1!=0)
        {
            dem[a[l]]--; l++;
        }
        if (dd==k) pres[i]=(pres[i-1]+pres[l-1])%MOD; else pres[i]=pres[i-1];
    }
    if (dd==k) cout << pres[l-1]; else cout <<0;
}