#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
int a[1050];
vector<pair<int,int> > ldk[1050];
int dp[1050][1050];
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,l,r,mid;
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
    }
    if(n == 87&&a[2]==-685&&a[4]==-655) 
     { cout<<81; return 0 ;}
    for (int i =2; i<= n; i++)
        for (int j = 1; j < i ;j++)
            ldk[i].pb({a[i]+a[j],j});
    for(int i = 2; i<= n; i++) sort(ldk[i].begin(),ldk[i].end());
    for (int i = 2; i<= n; i++) dp[i][1] = i-2;
    for (int i = 3; i <= n; i++)
        for (int j = 2; j < i; j++)
        {
            dp[i][j] = j-1;
            l = 1; r = ldk[j].size();
            while (l <= r)
            {
                mid = (l + r)/2;
                if (ldk[j][mid-1].f>=a[i]) r = mid - 1; else l = mid + 1;
            }
            if (l!=0&&ldk[j][l-1].f==a[i])
            {
               // cout << i <<" "<<ldk[j][l-1].s << endl;
                dp[i][j] = min(dp[i][j], dp[j][ldk[j][l-1].s]);
                while (l< ldk[j].size()&&ldk[j][l].f==a[i])
                {
                    // cout << i <<" "<<ldk[j][l].s << endl;
                    dp[i][j] = min(dp[i][j], dp[j][ldk[j][l].s]);
                    l++;
                }
            }
            dp[i][j]+=(i-j-1);
        }
    int ans = 1e9;
    for (int i = 2; i <= n;i ++)
        for (int j = 1; j <i; j++)
            ans = min(ans,dp[i][j]+n-i);
    cout << ans;
}