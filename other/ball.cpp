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

int n, cs[100005];
pair<int,int> a[100005];
void sol()
{
	int pos, dodai;
	cin >> pos >> dodai;
	pos = cs[pos];
	int l = pos + 1, r = n;
	while(1)
	{	
		int l = pos + 1, r = n;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if (a[mid].fi <= a[pos].fi + dodai)
			{
				l = mid + 1;
			}
			else r = mid - 1;
		}
		//cout << r << endl;
		dodai = dodai - a[r].fi + a[pos].fi;
		l = 1; int rr = r - 1;
		while(l <= rr)
		{
			int mid = (l + rr)/2;
			if (a[mid].fi >= a[r].fi - dodai)
			{
				rr = mid - 1;
			}
			else l = mid + 1;
		}
		dodai = dodai - a[r].fi + a[l].fi;
	//	cout << l << " " << r << endl;
		if (l == r)
		{
			cout << a[l].se << "\n";
			return;
		}
		if ((dodai/(a[r].fi - a[l].fi))%2) pos = r; else pos = l;
		dodai = dodai%(a[r].fi - a[l].fi);
	}
	cout << a[pos].se << "\n";
}
void solve() 
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi; a[i].se = i;
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) cs[a[i].se] = i;
	int query;
	cin >> query;
	while(query--) sol();
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
