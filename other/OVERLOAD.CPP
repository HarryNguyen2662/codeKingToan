#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005],ans[200005];
int main()
{
    freopen("OVERLOAD.INP","r",stdin);
     freopen("OVERLOAD.OUT","w",stdout);
   // ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    int n,m,k,l,r,mid; stack<int> ss;
    cin >> n >> m;
    for (int i= 1;i <=n ;i++) cin>> a[i];
    for (int i=1; i<=m;i++) 
    {
        cin>>b[i];
    }
    for (int i =n; i; i--)
    {
        while(m&&b[m]>=a[i]) {
            ss.push(m);
            m--;
        }
        if (!ss.empty()) {ans[i]=ss.top(); ss.pop();} else ans[i]=-1;
    }
    for (int i =1; i<=n;i++) cout<<ans[i]<<endl;
}