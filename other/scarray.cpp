#include<bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
int a[200005];
long long d[200005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,k,dem;
    long long ans = 1,sum;
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    cin >> k;
    //cout << endl;
    for (int i = 1; i<= n; i++)
    if (a[i]==a[i-1])
    {
        dem++;
        if(dem>k) sum = ((sum-d[i-k-1])%MOD+MOD)%MOD;
        d[i] = sum; sum += d[i]; sum%=MOD;
    }
    else
    {
        dem = 1;
        if (i-1!=0) ans = ans*d[i-1]%MOD;
        d[i-1] = 1; d[i] = 1; 
        sum = 2;
    }
    ans = ans*d[n]%MOD;
    cout << ans;
}