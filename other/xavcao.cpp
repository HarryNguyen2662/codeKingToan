#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
 int MAXN ;
const int oo = 1e9;
pair<int,int> a[100050],b[100050];
int da[100050],db[100050];
pair<long long,int> bit[100050];
void update(int x, int val)
{
    for (; x <= MAXN; x += (x&(-x)))
    {
        bit[x].f += val; bit[x].s+=1;
    }
}
pair<long long,int> sum(int x)
{
    pair<long long ,int> suu = {0,0};
    for (; x; x -= (x&(-x)))
    {
        suu.f+= bit[x].f;
        suu.s+= bit[x].s;
    }
    return suu;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);                                                                    
    int t,n;
    while (cin>>n)
    { 
        MAXN = n;
        for (int i  = 1 ;i <= n; i++)
            bit[i]= {0,0};
        for (int i = 1; i<= n; i++)
        {
            cin >> a[i].f >> b[i].f;
            a[i].s = i; b[i].s= i;
        }
        int kk =0;
    
        //cout<<kk<<endl;
        sort(a+1, a +1+n); sort(b+1,b+1+n);
        da[a[1].s] = 1;
        for (int i = 2; i <= n; i++) if (a[i].f == a[i-1].f) da[a[i].s] = da[a[i-1].s]; 
            else da[a[i].s] = i;
         db[b[1].s] = 1;
        for (int i = 2; i <= n; i++) if (b[i].f == b[i-1].f) db[b[i].s] = db[b[i-1].s]; 
            else db[b[i].s] = i;
        update(da[b[n].s],da[b[n].s]);
        //cout << b[n].s<<endl;
        long long ans = 0;
        long long su = da[b[n].s];
       // cout << e << endl;
        for (int i = n-1; i ; i--)
        {
            pair<long long,int> uu = sum(da[b[i].s]);
            //cout << uu.f << " "<< uu.s << endl;
            ans = ans + 1ll*db[b[i].s]*(su -1ll*da[b[i].s]*(n-i)-2ll*uu.f+2ll*uu.s*da[b[i].s]);
            //cout<<1ll*e*(su -1ll*da[b[i].s]*(n-i)-2ll*uu.f+2ll*uu.s*da[b[i].s])<<endl;
            su+= da[b[i].s];
            update(da[b[i].s],da[b[i].s]);
        }
        cout << ans<<endl;
    }
}   