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
bool kt;
string a[10005];
struct Trie
{
	struct Node
	{
		Node *child[10];
		int leaf, pass;
		Node()
		{
			for (int i = 0; i < 10; i ++) child[i] = NULL;
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

	void insert(string s)
	{
		Node *p = root;
		p -> pass ++;
		for (int i = 0; i < (int)s.size(); i++)
		{
			int x = s[i] - '0';
			if (p -> child[x] == NULL) p -> child[x] = new Node();
			p = p -> child[x];
			if (p -> leaf > 0) kt = true;
			p -> pass++;
			
		}
		if (p -> pass > 1) kt = true;
		p -> leaf++;
	}
	Node *erase(string s, int i, Node *p)
	{
		if (i == (int)s.size())
		{
			p -> leaf --;
			p -> pass --;
			if (p -> pass == 0)
			{
				delete p;
				p = NULL;
			}
			return p;
		}
		int x = s[i] - '0';
		p -> child[x] = erase(s, i + 1, p -> child[x]);
		p -> pass--;
		if (p -> pass == 0)
		{
			delete p;
			p = NULL;
		}
		return p;
	}
};
Trie ldk;

void solve() 
{
	int n;
	cin >> n;
	kt = false;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ldk.insert(a[i]);
	}
	for (int i = 1; i <= n; i++)
		ldk.erase(a[i], 0, ldk.root);
	if (kt) cout << "NO\n"; else cout << "YES\n";
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
    cin >> testcase;
    while(testcase--)
        solve();
}
