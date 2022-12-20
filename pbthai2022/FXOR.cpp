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

struct Trie
{
	int child[2];
	Trie()
	{
		child[0] = child[1] = 0;
	}
} node[3100004];

int cnt = 1;

void insert(int x)
{
	int p = 1;

	for (int i = 30; i >= 0; i--)
	{
		int id = ck(x, i);

		if (node[p].child[id] == 0) node[p].child[id] = ++cnt;

		p = node[p].child[id];
	}
}

long long find(int x)
{
	int p = 1;
	int res = 0;

	for (int i = 30; i >= 0; i--)
	{
		int id = ck(x, i);

		if (node[p].child[1 - id])
		{
			if (id == 0) res += mask(i);
			p = node[p].child[1 - id];
		}
		else
		{
			if (id == 1) res += mask(i);
			p = node[p].child[id];
		}
	}

	return res;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;

		insert(x); 
	}

	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;

		cout << find(x) << "\n";
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
