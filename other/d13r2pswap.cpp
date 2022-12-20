#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 
    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}
};

fenwicktree dk;

int mxx = 0, id1 = 1, id2 = 1;
int a[100005], mx[100005];

void f(int l, int r, int st, int ed)
{
	if (l > r) return;

	// cout << l << " " << r << " " << st << " " << ed << endl;

	int mid = (l + r) >> 1;

	if (a[mid] != mx[mid])
	{
		f(l, mid - 1, st, ed); f(mid + 1, r, st, ed);
		return;
	}

	int val = 0;
	int best = mid;


	for (int i = mid; i <= ed; i++)
	{
		if (i >= st)
		{	
			int va = dk.get(a[mid]) - dk.get(a[i]);
			if (va > val)
			{
				val = va; best = i;
			}
		}
		dk.update(a[i], 1);
	}

	if (val > mxx)
	{
		mxx = val;
		id1 = mid; id2 = best;
	}

	for (int i = mid; i <=  ed; i++)
	{
		dk.update(a[i], -1);
	}

	f(l, mid - 1, st, best); f(mid + 1, r, best, ed);
}

void solve() 
{	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mx[i] = max(mx[i-1], a[i]);
	}

	dk.reset(n);
	f(1, n, 1, n);

	ll res = 0;

	res += (id1 != id2);

	swap(a[id1], a[id2]);

	fenwicktree ldk; ldk.reset(n);

	for (int i = n; i; i--)
	{
		res += ldk.get(a[i]);

		ldk.update(a[i], 1);
	}

	cout << res;

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
