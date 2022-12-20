#include<bits/stdc++.h>
using namespace std;
#define l first
#define r second
int kthuc[1005],danhdau[1005];
pair<int,int> a[1005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    int n,m,k; char x; vector<int> ldk;
    cin >> n >>m >> k;
    for (int i =1 ; i<= n; i++)
    {
        kthuc[i]=i;
        cin>> a[i].l >> a[i].r;
    }
    for (int j = 1; j<= m; j++)
    {
        cin >> x;
        if (x=='L')
        for (int i = 1; i<=n; i++ )
            kthuc[i]=a[kthuc[i]].l;
        else
        for (int i = 1; i<=n; i++)
           kthuc[i]=a[kthuc[i]].r;
    }
    ldk.push_back(1); danhdau[1]=1;
    int u=1;
    while(!danhdau[kthuc[u]])
    {
        ldk.push_back(kthuc[u]);
        danhdau[kthuc[u]]=danhdau[u]+1;
        u=kthuc[u];
    }
    int kk = ldk.size()-danhdau[kthuc[u]]+1; k = (k-danhdau[kthuc[u]]+1)%kk;
    cout<<ldk[danhdau[kthuc[u]]-1+k];
}
