#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
int kt[MAXN+5];
int kk[MAXN+5];
int a[1050],b[1000050];
vector<int> ldk[1000050];
int dp[1050][1050];
int find(int p, int q)
{
    int l = 1, r = ldk[q].size()-1;
    while (l<= r)
    {
        int mid = (l+r)/2;
        if (ldk[q][mid-1]<= p) l = mid + 1; else r = mid - 1; 
    }
    return ldk[q][l-1];
}
void minimize(int &x, int y)
{
    if (x==-1||x>y)
    {
        x = y;
    }
}
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
    int n,m,x;
    cin >> n >> m; 
    for (int i = 1; i<= n; i++)
        cin >> a[i];
    for (int i = 1; i<= m; i++)
    {
        cin >> b[i];
        x = b[i];
       if ((int)ldk[x].size() == 0){
        ldk[x].pb(i); ldk[x].pb(0);
       }
       else 
        {
            ldk[x].back() = i; ldk[x].pb(0);
        }
    }
    memset(dp,-1,sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j<= i; j ++)
            if(dp[i][j]>=0)
            {
                minimize(dp[i+1][j],dp[i][j]);
                if ((int)ldk[a[i+1]].size()==0) continue;
                int val = find(dp[i][j],a[i+1]);
                if (val>0) minimize(dp[i+1][j+1],val);
            }
    int dodai;
    for (dodai = n; dodai ; dodai--)
    if (dp[n][dodai]!=-1)
    {
        cout << dodai<<endl; break;
    }
    vector<int> tv;
    while(n>0&&dodai>0)
    if (dp[n][dodai]==dp[n-1][dodai])
    {
        n--;
    }
    else
    {
        tv.pb(dp[n][dodai]);
        n--; dodai--;  
    }
    for (int i = tv.size()-1; i>=0; i--)
         cout << b[tv[i]] << " ";
}