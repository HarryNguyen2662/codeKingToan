#include <bits/stdc++.h>
using namespace std;
int dem[1000005],a[1000005];
int main ()
{
    freopen("KGOOD.INP ","r",stdin);
    freopen("KGOOD.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, l, luu = 0, dd=0, luu1, luu2;
    cin >> n >> k;
    l = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(dem[a[i]] == 0) dd++;
        dem[a[i]]++;
        while(dd > k && l < i)
        {
            dem[a[l]]--; if(!dem[a[l]]) dd--;
            l++;
        }
        if(i - l + 1 > luu)
        {
            luu1 = l; luu2 = i; luu = i - l +1;
        }
    }
    cout << luu1 << " "<<luu2;
}