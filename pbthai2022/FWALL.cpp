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

struct Trie
{
	int child[26]; pair<int, char> back; bool term;

	Trie()
	{
		for (int i = 0; i < 26; i++) child[i] = 0;
		back = {0, 0};
		term = false;
	}
};

Trie node1[1600005];

int cnt = 0, cmt = 0, node[1000005][27];
vector<int> ldk;

void add(const string &s)
{
	int p = 0;
	for (int i = 0 ; i < (int)s.size(); i++)
	{
		int id = s[i] - 'a';
		if (node[p][id] == 0) node[p][id] = ++cnt;
		p = node[p][id];
	}

}

void add1(const string &s)
{
	int p = 0;
	for (int i = 0 ; i < (int)s.size(); i++)
	{
		int id = s[i] - 'a';
		if (node1[p].child[id] == 0) node1[p].child[id] = ++cmt;
		node1[node1[p].child[id]].back = {p, s[i]};
		p = node1[p].child[id];
	}

	node1[p].term = true;
}

void dfs(int p = 0, int p1 = 0)
{
	if (node1[p].term)
	{
		cout << "-1";
		exit(0);
	}

	for (int i = 0; i < 26; i++)
	if (node1[p].child[i])
	{
		if (node[p1][i])
			dfs(node1[p].child[i], node[p1][i]);
		else ldk.pb(node1[p].child[i]);

	}
}


void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		char ti;
		cin >> ti;
		string s;
		cin >> s;
		if (ti == '+') add(s);
		else add1(s);
	}

	dfs();

	cout << (int)ldk.size() << "\n";
	vector<string> dk;

	for (auto v : ldk)
	{
		int cur = v;
		string re = "";
		while(cur)
		{
			re += node1[cur].back.se;
			cur = node1[cur].back.fi;
		}
		reverse(ALL(re));
		dk.pb(re);
	}

	sort(ALL(dk));

	for (auto v : dk) cout << v << "\n";
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
