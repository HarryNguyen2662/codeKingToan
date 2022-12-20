#include<bits/stdc++.h>
using namespace std;
long long f[100005];
long long kt[10000004];
int main()
{
    freopen("SMD.INP","r",stdin);
    freopen("SMD.OUT","w",stdout);
    int u,v,n,x,t;
    for (int i = 2; i*i<= 10000000; i++)
        if (!kt[i])
        {
            kt[i]=i;
            for (int j=i*i; j<=10000000; j+=i ) if (!kt[j]) kt[j]=i;
        }
    for (int i=2; i<=10000000; i++) if (!kt[i]) kt[i]=i;
    cin >> n >>t;
    for (int i=1; i<=n; i++)
    {
        cin >> x;
        f[i]=f[i-1]+kt[x];
    } 
    while(t--)
    {
        cin >> u>> v;
        cout << f[v]-f[u-1]+v-u+1<<endl;
    }
    //cout << kt[8]<<" "<< kt[9]<<" "<<kt[100];
}