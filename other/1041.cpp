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
int cnt = -1;
pair<char, int> sl[15];
char st[100];
bool ban[2000];
vector<int> ldk[100];
int k;
void trau(int id)
{
	cnt++;
	if (cnt == k)
	{
		for (int i = 1; i <= 30; i++) if (st[i] != 0) cout << st[i];
		exit(0);
	}
	for (int i = 1; i <= 9; i++)
	{
		bool kt = true;
		for (auto v : ldk[id]) if (sl[i].fi == st[v])
		{
			kt = false;
			break;
		}
		if (!kt) continue;
		if (sl[i].se)
		{
			sl[i].se--;
			st[id] = sl[i].fi;
			trau(id+1);
			sl[i].se++;
			st[id] = 0;
		}
	}
}
void solve() 
{
	sl[1].fi = 'G'; sl[2].fi = 'S'; sl[3].fi = 'P'; sl[4].fi = 'V'; sl[5].fi = 'H';
	sl[6].fi = 'C'; sl[7].fi = 'U'; sl[8].fi = 'T'; sl[9].fi = 'E';
	for (int i = 1; i <= 9; i++) 
	{
		cin >> sl[i].se;
	}
	sort(sl + 1, sl + 10);
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		ldk[y].pb(x);
	}
	cin >> k;
	trau(1);
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
