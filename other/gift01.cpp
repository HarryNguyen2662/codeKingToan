#include<bits/stdc++.h>
using namespace std;
long long dp[1000005];
int main()
{
    freopen("yeunhi.txt","r",stdin);
    int n,k,x; deque<int> s; long long ans=0,ans1;
    cin >> n>>k;
    s.push_back(0);
    for (int i = 1; i<=n; i++)
    {
        cin>>x;
        ans=ans+x;
        dp[i]=dp[s.front()]+x;
        if(s.front()==i-k) s.pop_front();
        while(!s.empty()&&dp[s.back()]>=dp[i]) s.pop_back();
        s.push_back(i);
    }
    if (k>n)
    {
        cout<<ans; return 0;
    }
    ans1=dp[n];
    for (int i=n-1; i>=n-k+1; i--) ans1=min(ans1,dp[i]);
    cout<<ans-ans1;
}