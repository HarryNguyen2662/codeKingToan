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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
struct Trie
{
	struct Node
	{
		Node *child[26];
		int leaf;
		int pass;
		Node()
		{
			for (int i = 0; i < 26; i++) child[i] = NULL;
			leaf = 0;
			pass = 0;
		} 
	};

	Node *root;

	Trie()
	{
		root = new Node();
		root -> pass = 1;
	}

	void insert(string s, int id)
	{
		Node *p = root;
		p -> pass ++;
		for (int i = 0; i < (int)s.size(); i++)
		{
			int x = s[i] - 'a';
			if (p -> child[x] == NULL) p -> child[x] = new Node();
			p = p -> child[x];
			p -> pass++;
		}
		p -> leaf = id;
	}
	int find(string s)
	{
		Node *p = root;
		for (int i = 0; i < (int)s.size(); i++)
		{
			int x = s[i] - 'a';
			if (p -> child[x] == NULL) return -1;
			p = p -> child[x];
			if (p -> leaf > 0) return p -> leaf;
		}
		return -1;
	}
	Node *erase(string s, int i, Node *p)
	{
		if (i == (int)s.size())
		{
			p -> pass--; p -> leaf = 0;
			if (p -> pass == 0)
			{
				delete p;
				p = NULL;			
			}
			return p;
		}
		int x = s[i] - 'a';
		p -> child[x] = erase(s, i + 1, p -> child[x]);
		p -> pass --;
		if (p -> pass == 0)
		{
			delete p;
			p = NULL;
		}
		return p;
	}
};
string a[2000005];
int re[2000005], cs[2000005];
bool cmp (const int &x, const int &y)
{
	if ((int)a[x].size() == (int)a[y].size())
	{
		return a[x] < a[y];
	}
	return (int)a[x].size() < (int)a[y].size();
}

void solve() 
{
	Trie ldk;
	int n;
	cin >> n;
	for (int i = 1; i <= 2*n; i++) cs[i] = i;
	for (int i = 1; i <= 2*n; i++) cin >> a[i];
	sort(cs + 1, cs + 2*n + 1, cmp);
	for (int i = 1;  i <= 2*n; i++)
	{
		//cout << a[i] << endl;
		re[cs[i]] = ldk.find(a[cs[i]]);
		if (re[cs[i]] == -1) ldk.insert(a[cs[i]], cs[i]);
		else ldk.erase(a[re[cs[i]]], 0, ldk.root);
	}	
	for (int i = 1; i <= 2*n; i++) if (re[i] != -1) cout << re[i] << " " << i << endl;
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
