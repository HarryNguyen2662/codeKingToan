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

int n, q;
int fen1[100005], fen2[100005], ha[100005], co[100005];
void update1(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen1[id] += val;
}
int get1(int id)
{
	int res= 0;
	for (; id; id -= (id&(-id))) res += fen1[id];
	return res;
}
void update2(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen2[id] += val;
}
int get2(int id)
{
	int res= 0;
	for (; id; id -= (id&(-id))) res += fen2[id];
	return res;
}
void solve() 
{
	cin >> n >> q;

	while(q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x, y;
			cin >> x >> y;
			if (ha[x] == 0) update1(x, 1); 
			ha[x]++;
			if (co[y] == 0) update2(y, 1);
			co[y]++;
		}
		else if (t == 2)
		{
			int x, y;
			cin >> x >> y;
			ha[x]--;
			if (ha[x] == 0) update1(x, -1);
			co[y]--;
			if (co[y] == 0) update2(y, -1);
		}
		else
		{
			int u, v, x, y;
			cin >> u >> v >> x >> y;
			if (get1(x) - get1(u-1) == x - u + 1 || get2(y) - get2(v-1) == y - v + 1)
			cout << "Yes\n"; else cout << "No\n";
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
