#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int lim = 1e6 + 2;;
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
map<string,int> dd;
string s[105];
int check[105][105];
void solve()
{
    int k, n;
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
    {
        string ss;
        cin >> ss;
        dd[ss] = i;
    }
    for (int i = 1; i <= k; i++)
    {
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++)
        {
            int id1 = dd[s[i]];
            bool kt = false;
            for (int j = i + 1; j <= n; j++)
            {
                int id2 = dd[s[j]];
                if (s[j-1] > s[j]) kt = true;
                if (kt) 
                    {
                        check[id2][id1] = 1, check[id1][id2] = -1;
                    }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        if (i == j) cout << "B";
        else if (check[i][j] == 1) cout << "1";
        else if (check[i][j] == -1) cout << "0";
        else cout << "?";
        cout << "\n";
    }
}
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    // 
    #endif
    //freopen("dienbien.inp","r",stdin); freopen("dienbien.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}