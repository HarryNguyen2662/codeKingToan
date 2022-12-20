#include<bits/stdc++.h>
using namespace std;
#define s second
#define f first
const int maxn = 1e5+3;
int a[100005], tp[100005][2], xx[100005];
pair<int, int> dp[100005][2], x[100005];
void update(int p, pair<int, int> val, int loai)
{
    if (loai == 1)
    { 
        for (int i = p; i;  i -= i & -i)
            dp[i][1] = max(dp[i][1], val);
    }
    else
    {
        for (int i = p; i <= maxn ; i += i & -i)
            dp[i][0] = max(dp[i][0], val);
    }
}
pair<int, int> getmax(int p, int loai)
{
    pair<int, int > ans = {0, 0};
    if (loai == 1)
    {
        for(int i = p; i; i -= i & -i)
        ans = max(ans, dp[i][0]);
    }
    else
    {
        for(int i = p;  i <= maxn ; i += i & -i)
        ans = max(ans, dp[i][1]);
    }
    return ans;
}
int main()
{
   // freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, luu, ans = 0, check; vector<int> ldk;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i].f; xx[i] = x[i].f;
        x[i].s = i;
    }
    sort(x + 1, x + 1 + n);
    a[x[1].s] = 1;
    for (int i = 2; i <= n; i++)
        if (x[i].f!=x[i-1].f) a[x[i].s] = a[x[i-1].s] + 1; else a[x[i].s] = a[x[i-1].s ];
    // for (int i  =1 ; i <=n ;i++)
    //     cout << a[i] << " ";
       // cout << endl; 
    for (int i = 1; i <= n; i++)
    {
        pair<int, int > ans1 = getmax(a[i] + 1, 0), ans2 = getmax(a[i] - 1, 1);
        tp[i][0] = ans1.s; tp[i][1] = ans2.s;
        update(a[i], {ans1.f + 1, i} , 0); update(a[i], {ans2.f + 1, i}, 1);
         //cout << ans. << endl;
        if(ans1.f+1 > ans)
        {

            ans = ans1.f + 1;
            luu = i; check = 0;
        }
        if(ans2.f + 1 > ans)
        {
            ans = ans2.f + 1;
            luu = i; check = 1;
        }
    } 
    cout << ans << endl;
   // cout << luu << " ";
    ldk.push_back(luu);
    while(tp[luu][check]!=0)
    {
        luu=tp[luu][check]; check =( check == 0);
        ldk.push_back(luu);
    }
    for (int i = ldk.size()- 1; i >= 0; i--)
        cout << xx[ldk[i]]<< " ";
}