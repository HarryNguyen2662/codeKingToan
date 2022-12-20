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

long long a[200005];

map<long long,int> dem;

void solve() 
{
 	int n, m;
 	cin >> n >> m;

 	for (int i = 1; i <= n; i++) cin >> a[i];

 	while(m--)
 	{
 		int type, l, r;
 		cin >> type >> l >> r;

 		if (type == 1)
 		{
 			int x; cin >> x;
 			for (int i = l; i <= r; i++) a[i] += x;
 		}
 		else
 		{
 			long long re = oo18;
 			for (int i = l; i <= r; i++) 
 			{
 				dem[a[i]]++;
 				if (dem[a[i]] > (r - l + 1)/2)
 				{
 					re = a[i]; break;
 				}
 			}
 			for (int i = l; i <= r; i++) dem[a[i]] = 0;

 			if (re == oo18)
 			{
 				cout << "IMPOSSIBLE\n";
 			}
 			else cout << re << "\n";
 		}
 	}
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
    //cin >> testcase;
    while(testcase--)
        solve();
}