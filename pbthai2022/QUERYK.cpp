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

int cnt = 1;
struct Trie
{
	int child[2]; int pass;
	Trie()
	{
		child[0] = child[1] = 0;
		pass = 0;
	}
} node[3100005];


void insert(int val)
{
	int p = 1; node[p].pass++;
	for (int i = 30; i >= 0; i--)
	{
		//cout << p << " ";
		int id = ck(val, i);
		if (node[p].child[id] == 0) node[p].child[id] = ++cnt;
		p = node[p].child[id];
		//cout << val << " "<< id << " " << p << endl;
		node[p].pass++;
	}
}

int erase(int val, bool all, int i = 30, int p = 1)
{
	if (node[p].pass == 0) return 0;
	if (i == -1)
	{
		if (all) 
		{
			int w = node[p].pass;
			node[p].pass = 0;
			return w;
		}
		else
		{
			node[p].pass--;
			return 1;
		}
	}
	int id = ck(val, i);
	if (node[p].child[id] == 0) return 0;
	int w = erase(val, all, i-1, node[p].child[id]);
	node[p].pass -= w;
	return w;
}

int get(int k)
{
	int res = 0;
	int p = 1;
	for (int i = 30; i >= 0; i--)
	{
		int w = 0;
		if (node[p].child[0])
		{
			w = node[node[p].child[0]].pass;
		}
		if (k > w)
		{
			k -= w;
			res += mask(i);
			p = node[p].child[1];
		}
		else
		{
			p = node[p].child[0];
		}
		//cout <<w << " " <<  k<< endl;
	}

	return res;
}

int gett(int val)
{
	int p = 1;
	int res = 0;
	if (val < 0) return 0;
	for (int i = 30; i >= 0; i--)
	{
		int id = ck(val, i);
		if (id && node[p].child[0]) res += node[node[p].child[0]].pass;
		if (node[p].child[id] == 0) return res;
		p = node[p].child[id];
	}
	res += node[p].pass;

	return res;
}


void solve() 
{	
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x; x += oo;
		insert(x);
	}
	int q;
	cin >> q;
	long long su = 0;
	while(q--)
	{
		int type;
		cin >> type;
		if (type <= 3)
		{
			long long s;
			cin >> s;
			int w = abs(su + s)%(2*oo + 1);
			if (type == 1) insert(w);
			else if (type == 2) erase(w, 0);
			else erase(w, 1);
		}
		else if (type == 4)
		{
			int k; cin >> k;
			int g = get(k) - oo;
			cout << g << "\n";
			su += g; 
		}
		else
		{
			int l, r;
			cin >> l >> r;
			l += oo; r += oo;
			cout << gett(r) - gett(l - 1) << "\n"; 
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
