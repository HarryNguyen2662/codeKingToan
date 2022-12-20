#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[800005];
int main()
{
     freopen("SCHE2N.INP","r",stdin);
      freopen("SCHE2N.OUT","w",stdout);

   // ios_base::sync_with_stdio(0);
  //  cin.tie(0); cout.tie(0);
    int n; int ans=0;
    cin>> n;
    for (int i = 1; i<= 2*n; i++)
        {
            cin >> a[i].first>>a[i].second;
            a[i].first=a[i].first-a[i].second;
        }
    sort(a+1,a+1+2*n);
    for (int i = 1; i<=n; i++)
        ans+=(a[i].first+a[i].second);
    for (int j = n+1; j<=2*n; j++)
        ans+=a[j].second;
    cout<<ans;
}