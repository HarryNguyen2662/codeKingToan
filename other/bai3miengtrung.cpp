#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int a[500050];
int b[500050];
pair<int,int> dd[500050];
vector<int> ldk[500050];
int non[100050][55];
bool check(long long x)
{
    for (int i  = 2; i*i <= x; i++)
        if (x%i == 0) return false;
    return true;
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
    int n , k;
    cin >> n >> k;
    int m = n*k;
    for (int i = 1; i <= m; i++)
    {
        cin >>  a[i];
        ldk[a[i]].pb(i);
    }
    for (int i = 1; i<= m; i++) cin >> b[i];
    int ans = 1;
    dd[1] ={b[1],0}; non[b[1]][0] = 1;
    for (int i = 2; i<= m; i++)
    for (int j = ldk[b[i]].size()-1; j >=0; j--)
    if(non[b[i]][j]==0)
    {
        int k = ldk[b[i]][j];
        //cout << ans <<" "<<k << endl;
        if (k < ldk[dd[1].f][dd[1].s])
        {
           // non[dd[1].f][dd[1].s] = 0;
            dd[1] ={b[i],j}; non[b[i]][j] = 1;
        }
        else if (k > ldk[dd[ans].f][dd[ans].s])
        {
            ans++;
            dd[ans] ={b[i],j}; non[b[i]][j] = 1;
        }
        else
        {
            int l = 1, r = ans;
            while(l <= r)
            {
                int  mid = (l+r)/2;
                if (ldk[dd[mid].f][dd[mid].s] < k) l = mid + 1; else r= mid -1;
            }
           // non[dd[l].f][dd[l].s] = 0;
            dd[l] ={b[i],j}; non[b[i]][j] = 1;
        }
    }
    cout << ans;
}