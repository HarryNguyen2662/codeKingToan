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

int a[200005], vec[200005];
struct NODE
{
	int gt, left, right;
	NODE() {}
	NODE(int gt, int left, int right) : gt(gt), left(left), right(right) {}
} sg[10000005];
int numnode = 0;

int update(int l, int r, int vt, int val, int oldid)
{
	if (l == r)
	{
		++numnode;
		//cout << numnode << endl;
		sg[numnode] = NODE(val, 0, 0);
		return numnode;
	}

	int mid = (l + r)/2;
	int cur = ++numnode;

	if (vt <= mid)
	{
		sg[cur].left = update(l, mid, vt, val, sg[oldid].left);
		sg[cur].right = sg[oldid].right;
	}	
	else
	{
		sg[cur].left = sg[oldid].left;
		sg[cur].right = update(mid + 1, r, vt, val, sg[oldid].right);
	}

	sg[cur].gt = sg[sg[cur].left].gt + sg[sg[cur].right].gt;

	return cur;
}

int get(int ty, int l, int r, int u, int v)
{

	if (v < l || r < u) return 0;
	//cout << ty << endl;
	if (u <= l && r <= v)
	{
		return sg[ty].gt;
	}
	int mid = (l + r)/2; 	

	return get(sg[ty].left, l, mid, u, v) + get(sg[ty].right, mid + 1, r, u, v);
}

map<int,int> dd;

void solve() 
{
	int n, q;
	cin >> n >> q;
	
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		int t = dd[x];
		vec[i] = update(1 , n, i, 1, vec[i-1]);
		//cout << vec[i] << endl;
		if (t) vec[i] = update(1, n, t, 0, vec[i]);
		//cout << vec[i] << " " <<  get(vec[i], 1, n, i, i) << endl;
		dd[x] = i;
	}
	
	int res = 0;
	//cout << get(vec[4], 1, n, 1, 4) << endl;
	//cout << endl;
	while(q--)
	{
		int u, v;
		cin >> u >> v;
		u = (u + res)%n + 1; v = (v + res)%n + 1;
		int l = min(u, v), r = max(u, v);
		//cout << vec[r] << endl;
		//cout << l << " " << r << endl;
		res = get(vec[r], 1, n, l, r);
		cout << res << "\n";
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
