#include <bits/stdc++.h>
using namespace std;
long long l, r;
long long f[15], du[15];
void khoitao()
{
     f[0] = 1;
    for (int i = 1; i <= 10; i++)
    {
        f[i] = f[i - 1] * i;
    }
    for (int i = 1; i <= 10; i++)
    {
        du[i] = du[i - 1] + 9 * f[9] / f[10 - i];
    }
}
long long solve1(long long a)
{
    if(a < 10)
        return a;
    if(a >= 9876543210)
        return du[10];
    int n = 0;
    long long ans = 0;
    long long m = a;
    int pos[11];
    while (m > 0)
    {
        pos[++n] = m % 10;
        m /= 10;
    }
    ans = du[n - 1];
    ans += (pos[n] - 1) * (f[9] / f[10 - n]);
    bool kt[11];
    memset(kt, false, sizeof(kt));
    kt[pos[n]] = true;
    for (int i = n-1; i >= 1; i--)
    {
        int dem = 0;
        for (int j = 0; j < pos[i]; j++)
        {
            if (!kt[j])
            {
                dem++;
            }
        }
        if (i == 1 && !kt[pos[i]])
        {
            dem++;
        }
        ans = ans + dem * (f[9 - n + i] / f[10 - n]);
        if (kt[pos[i]])
        {
            break;
        }
        kt[pos[i]] = true;
    }
    return ans;
}
void solve()
{
    khoitao();
    cin >> l >> r;
    cout << solve1(r) - solve1(l - 1) ;
}
int main() 
{
    freopen("lololoin.txt","r",stdin);
    solve();
    return 0;
}
    