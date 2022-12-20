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

bool check[2000];
void solve() 
{
	int n;
	while(cin >> n)
	{
		for (int i = 1; i <= n; i++)
		{	
			string s, ss;
			cin >> s >> ss;
			int st = ((s[0] - '0')*10 + (s[1] - '0'))*60 + (s[3] - '0')*10 + (s[4] - '0');
			int ed = ((ss[0] - '0')*10 + (ss[1] - '0'))*60 + (ss[3] - '0')*10 + (ss[4] - '0') -;
			if (st <= ed)
			{
				for (int j = st; j <= ed; j++) check[j] = true;
			}
			else
			{
				for (int j = st; j <= 1439; j++) check[j] = true;
				for (int j = 0; j <= ed; j++) check[j] = true;
			}
		}
		bool kt = true;
		for (int i = 0; i <= 1439; i++) if (check[i])
		{
			check[i] = false;
		} else kt = false;
		if (kt) cout << "bubbletea is delicious!\n"; else cout << "huhuhu\n";
	}
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
