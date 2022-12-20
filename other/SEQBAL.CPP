#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SEQBAL.INP","r",stdin);
    freopen("SEQBAL.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x,l; int sum,ans = 0; vector<pair<int,int> > ldk; 
    cin >> n;
    ldk.push_back({0,0});
    for  (int i = 1;i <= n; i++)
    { 
        cin >> x;
        if (x) sum=sum+1; else sum=sum-1;
        ldk.push_back({sum,i});
    }
    l = ldk[0].second;
    sort(ldk.begin(),ldk.end());
    for (int i = 1; i< n; i++)
        if (ldk[i].first!=ldk[i-1].first)
        {
            ans = max(ans,ldk[i-1].second-l);
            l = ldk[i].second;
        }
    ans = max(ans,ldk[n-1   ].second-l);
    cout << ans;
}