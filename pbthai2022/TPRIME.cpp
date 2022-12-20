#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 17
#define mask(i) (1ll << (i))
#define setp(x) setprecision(x)
#define ALL(v) v.begin(), v.end()
#define ck(n, i) (((n) >> (i)) & 1) 
#define getbit(x) __builtin_popcount(x)

const double PI = acos(-1);
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789;

const int oo = 1e9;
const long long oo15 = 1e15, oo18 = 1e18+3, oooo = 922372036854775807;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int lim = 100000;

int pri[lim + 5], mo[lim + 5];
long long b[lim + 5];

void solve() 
{
    int n, m;
    vector<int> ldk, dk, re;
    cin >> n >> m;
    if (n > m) swap(n, m);

    for (int i = 1; i*i <= m; i++)
    {
        ldk.pb(i);   
    }
    for (int i = sqrt(m); i >= 1; i--) ldk.pb(m/i); 
    for (int i = sqrt(n); i >= 1; i--) dk.pb(n/i);  
    int id = 0, id1 = 0;
    while(true)
    {
        if (id < (int)ldk.size() && id1 < (int)dk.size())
        {
            if (ldk[id] < dk[id1])
            {
                re.pb(ldk[id]); id++;
            }
            else
            {
                re.pb(dk[id1]); id1++;
            }
        }
        else if (id < (int)ldk.size())
        {
             re.pb(ldk[id]); id++;
        }
        else if (id1 < (int)dk.size())
        {
              re.pb(dk[id1]); id1++;
        }
        else break;
    }

    long long res = 0;

    //cout << n/3 << " " << m/3 << endl;

    for (int i = 1; i < (int)re.size(); i++)
    {
        //cout << re[i] << endl;
        res += 1ll*(n/re[i])*1ll*(m/re[i])*(b[re[i]] - b[re[i - 1]]);
    }

    cout << res << "\n";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    
    mo[1] = 1;
        
    for (int i = 1; i <= lim; i++) pri[i] = i;

    for (int i = 1; i <= lim; i++)
    for (int j = 2*i; j <= lim; j += i)
    {
        if (i != 1 && pri[i] == i) pri[j] = i;
        mo[j] -= mo[i];
    }

    for (int i = 2; i <= lim; i++)
    {
        int val = i;
        b[i] = b[i-1];   
        while(val != 1)
        {
            int w = pri[val];
            b[i] += mo[i/w];
            while(val % w == 0) val /= w;
        }
    }

    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
