#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define NMOD 2
const double PI = 3.14159265389793238462643383279502884197169;
const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
const long long MOD = 1e9 + 7;
const int MAXN = 500000;
const int oo = 1e9;
const long long BASE = 256;
long long pw[NMOD][500001];
bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else return false;
}
void preparepw()
{
    for (int i = 0; i < NMOD; i ++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= MAXN; j++) pw[i][j] = pw[i][j-1]* BASE % HSMOD[i];
    }
}
struct HSS
{   
    int len;
    vector<long long> ps[NMOD];
    HS (string s)
    {
        int n = s.size(); len = n;
        for (int i = 0 ; i < NMOD; i ++) 
            {
                ps[i].resize(n + 1);
                ps[i][0] = 0;
                for (int j = 1; j <= n; j++) ps[i][j] = (ps[i][j-1] +1ll*s[j-1]*pw[i][j]%HSMOD[i])%HSMOD[i];
            }
    } 
    int qy(int l, int r, int type)
    {
        l++; r ++;
        return (ps[type][r] - ps[type][l-1] + HSMOD[type])%HSMOD[type]*pw[type][len-r]%HSMOD[type];
    }
};
HSS ss;
string s;
bool check(int l, int r, int u , int v)
{
    int x = 1, y =r-l+1;
    while (x <= y)
    {
        int mid = (x + y)/2;
        if (ss.qy(l,l + mid - 1,0) == ss.qy(u, u + mid -1, 0)&&ss.qy(l,l + mid - 1,1) == ss.qy(u, u + mid -1, 1))
        x = mid + 1; else y = mid - 1;
    }
    if (y == r - l + 1) return false;
    else return s[l+y] > s[u+y];
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    // freopen("unique-substring.inp","r", stdin);
    // freopen("unique-substring.out","w", stdout);
    preparepw();
    cin >> s;
    int n = s.size();
    ss.HS(s);
    int l = 1, r = s.size();
    while (l <= r)
    {
        int mid = (l + r) / 2;
        vector<pair<int,int>> ldk;
        for (int i = 0; i <= n - mid; i ++)
        {
            ldk.pb({ss.qy(i, i + mid - 1,0), ss.qy(i, i + mid - 1, 1)});
        }
        sort(ldk.begin(), ldk.end());
        bool kt = false;
        for (int i = 0; i <= n - mid ; i ++) 
        if((i == 0 || ldk[i]!=ldk[i-1]) && (i == n-mid || ldk[i]!= ldk[i+1]))
        {
            kt = true;
            break;
        }
        if (kt) r = mid -1; else l = mid + 1;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << s[i] <<" "<<ss.qy(i,i,0)<<endl;
    // }
    //cout << s[0] << " "<<s[2]<<endl;
    vector<pair<pair<int,int>,int> > ldk;
    r = l; l = - 1;
    for (int i = 0; i <= n - r; i ++)
    {
        //cout << s[i] <<s[i+1] <<" "<<ss.qy(i,i+r-1,1)<<endl;
        ldk.pb({{ss.qy(i, i + r - 1,0), ss.qy(i, i + r - 1, 1)} , i });
    }
    sort(ldk.begin(),ldk.end());
    for (int i = 0; i <= n - r ; i ++) 
        if((i == 0 || ldk[i].fi!=ldk[i-1].fi) && (i == n-r|| ldk[i].fi!= ldk[i+1].fi))
        {
            if (l == -1 ||check(l,l + r - 1,ldk[i].se, ldk[i].se + r - 1)) {
                
                l = ldk[i].se;
            }
        }
    for (int i = l; i <= l + r - 1; i++) cout << s[i];
}   