#include<bits/stdc++.h>
using namespace std;
long long dp[19][170][1500];
vector<int> a;
void biendoi(long long n)
{
    a.clear();
    while(n)
    {
        a.push_back(n%10);
        n=n/10;
    }
}
long long solve(int i, int gh, int sum, int sum2)
{
    if (i==-1)
    {
        return (__gcd(sum,sum2)==1);
    }
    if (!gh&&dp[i][sum][sum2]!=-1) return dp[i][sum][sum2];
    int k;
    if (gh==0) k = 9; else k =a[i];
    long long ans = 0;
    for (int j= 0 ;j <= k ;j++)
    {
        int newgh=(j==a[i]) ? gh : 0;
        ans +=solve(i-1, newgh, sum +j, sum2+j*j );
    }
    if (!gh) dp[i][sum][sum2] = ans;
    return ans;
}
int main()
{
    freopen("COUNTNUM.INP", "r", stdin);
    freopen("COUNTNUM.OUT", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    int t; long long l, r;
    cin>> t;
    memset(dp, -1 ,sizeof dp);
    while(t--)
    {
        cin >> l >> r;
        biendoi(r);
        long long ans1= solve(a.size()-1,1,0,0);
        biendoi(l-1);
        long long ans2= solve(a.size()-1,1,0,0);
        cout << ans1-ans2 << endl;
    }
}