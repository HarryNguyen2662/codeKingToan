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
	int child[26]; bool leaf;

	Trie()
	{
		for (int i = 0; i < 26; i++) child[i] = 0;
		leaf = false;
	}
} node[5005];
struct DATA
{
	int fii, see, tri;
} trace[2005][2005];

int cnt = 1;
bool ok[2005][2005];

void insert(const string &s)
{
	int p = 1;
	for (int i = 0; i < (int)s.size(); i++)
	{
		int id = s[i] - 'a';
		if (node[p].child[id] == 0) node[p].child[id] = ++cnt;
		p = node[p].child[id];
	}
	node[p].leaf = true;
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}

	ok[1][1] = true;

	queue<pair<int,int>> iq;
	iq.push({1, 1});

	while(!iq.empty())
	{
		int id = iq.front().fi, id1 = iq.front().se; iq.pop();

		if (id != id1 && node[id].leaf && node[id1].leaf)
		{
			vector<char> dk, ldk;
			while(id != 1)
			{
				int nid = trace[id][id1].fii, nid1 = trace[id][id1].see, kt = trace[id][id1].tri + 'a';
				dk.pb(kt); ldk.pb(kt);
				if (nid < 0)
				{
					dk.pb('+'); nid = -nid;
				}
				if (nid1 < 0)
				{
					ldk.pb('+'); nid1 = -nid1;
				}
				id = nid; id1 = nid1;
			}
			reverse(ALL(dk)); reverse(ALL(ldk));
			for (auto v : dk) cout << (char)v; cout << "\n"; for (auto v : ldk) cout << (char)v;

			return;
		}

		for (int i = 0; i < 26; i++)
		{
			if (node[id].child[i] && node[id1].child[i] && ok[node[id].child[i]][node[id1].child[i]] == false)
			{
				ok[node[id].child[i]][node[id1].child[i]] = true;
				trace[node[id].child[i]][node[id1].child[i]] = {id, id1, i};
				iq.push({node[id].child[i], node[id1].child[i]});
			}

			if (node[id].leaf && node[1].child[i] && node[id1].child[i] && ok[node[1].child[i]][node[id1].child[i]] == false)
			{
				ok[node[1].child[i]][node[id1].child[i]] = true;
				trace[node[1].child[i]][node[id1].child[i]] = {-id, id1, i};
				iq.push({node[1].child[i], node[id1].child[i]});
			}

			if (node[id1].leaf && node[id].child[i] && node[1].child[i] && ok[node[id].child[i]][node[1].child[i]] == false)
			{
				ok[node[id].child[i]][node[1].child[i]] = true;
				trace[node[id].child[i]][node[1].child[i]] = {id, -id1, i};
				iq.push({node[id].child[i], node[1].child[i]});
			}
		}
	}
	cout << "-1";
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
