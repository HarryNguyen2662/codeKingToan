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

int n;
long long a[500][500], b[500][500], c[500], d[500], e[500];

void solve() 
{

	cin >> n;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
	{
		cin >> b[i][j];
	}
	for (int t = 1; t <= 7; t++)
    {
        for (int i = 0; i < n; i++) d[i] = rng()%10 + 1;
        for (int i = 0; i < n; i++)
        {   
            c[i] = 0;  
            for (int j = 0; j < n; j++) c[i] += d[j]*a[j][i]; 
        }
        for (int i = 0; i < n; i++)
        {
            long long w = 0;
            for (int j = 0; j < n; j++) w += c[j]*a[j][i];
            e[i] = w;
        }
        for (int i = 0; i < n; i++)
        {
            long long w = 0;
            for (int j = 0; j < n; j++) w += e[j]*a[j][i];
            c[i] = w;
        }
        for (int i = 0; i < n; i++)
        {
            long long w = 0;
            for (int j = 0; j < n; j++) w += d[j]*b[j][i];
            if (w != c[i])
            {   
                cout << "NO\n";
                return;
            }
        } 
    }
	cout << "YES\n";
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
    int testcase = 1;
   	cin >> testcase;
    while(testcase--)
        solve();
}
