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
		Node *child[2];
		int pass;
		Node()
		{
			for (int i = 0; i < 2; i++) child[i] = NULL;
			pass = 0;
		}
	};

	Node *root;

	Trie()
	{
		root = new Node();
		root -> pass = 1;
	}

	void insert(int val)
	{
		Node *p = root;
	 	p -> pass ++;
	 	for (int i = 29; i >= 0; i--)
	 	{
	 		bool x = ck(val, i);
	 		if (p -> child[x] == NULL) p -> child[x] = new Node();
	 		p = p -> child[x];
	 		p -> pass++; 
	 	}
	}
	int get(int val)
	{
		int res = 0;
		Node *p = root;
		for (int i = 29; i >= 0; i--)
		{
			bool x = ck(val, i);
			if (p -> child[1-x] != NULL)
			{
				res += mask(i);
				p = p -> child[1-x];
			}
			else p = p -> child[x];
		}
		return res;
	}
};
int a[100005];
void solve() 
{
	int n;
	Trie ldk;
	cin >> n;
	int res = 0;
	cin >> a[1]; ldk.insert(a[1]);
	for (int i = 2; i <= n; i++)
	{
		cin >> a[i];
		res = max(res, ldk.get(a[i]));
		ldk.insert(a[i]);
	}
	cout << res << "\n";
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
