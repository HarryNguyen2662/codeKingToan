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
	struct node
	{
		node *child[2];
		int pass;
		node()
		{
			pass = 0;
			for (int i = 0 ; i < 2; i++) child[i] = NULL;
		}
	};

	node *root;

	Trie()
	{
		root = new node();
		root -> pass = 1;
	}

	void insert(const int &val) 
	{
		node *p = root;
		p -> pass++;
		for (int i = 30; i >= 0; i--)
		{
			bool x = ck(val, i);
			if (p -> child[x] == NULL) p -> child[x] = new node();
			p = p -> child[x];
			p -> pass++;
		}
	}

	int get1(const int &val) 
	{
		int count = 0;
		node *p = root;
		for (int i = 30; i >= 0; i--)
		{
			bool x = ck(val, i);
			if (x && p -> child[0] != NULL) count += p -> child[0] -> pass;
			if (p -> child[x] == NULL) break;
			p = p -> child[x]; 
		}
		return count;
	}

	int get(const int &val) 
	{
		int count = 0;
		node *p = root;
		for (int i = 30; i >= 0; i--)
		{
			bool x = ck(val, i);
			if (!x && p -> child[1] != NULL) count += p -> child[1] -> pass;
			if (p -> child[x] == NULL) break;
			p = p -> child[x]; 
		}
		return count;
	}

	node *erase(int val, int i, node *p )
	{
		if (i == -1)
		{
			p -> pass--;
			if (p -> pass == 0)
			{
				delete p;
				p = NULL;
			}
			return p;
		}
		p ->pass--;
		p -> child[ck(val,i)] = erase(val, i - 1, p -> child[ck(val, i)]);
		if (p -> pass == 0)
		{
			delete p;
			p = NULL;
		}
		return p;
	}
};
Trie bit[100005];
int a[100005];
int n;
void update(int id, int val)
{
	for (; id <= n; id += (id&(-id))) bit[id].insert(val);
}
void remove(int id, int val)
{
	for (; id <= n; id += (id&(-id))) bit[id].erase(val, 30, bit[id].root);
}
int bitget(int id, int val)
{
	int count = 0;
	for (; id; id -= (id&(-id))) count += bit[id].get(val);
	return count;
}
int bitget1(int id, int val)
{
	int count = 0;
	for (int i = n; i; i -= (i&(-i))) count += bit[i].get1(val);
	for (; id; id -= (id&(-id))) count -= bit[id].get1(val);
	return count;
}
void solve() 
{
	long long res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		int val;
		cin >> a[i];
		update(i, a[i] + oo);
		//cout << bitget(i, a[i] + oo) << endl;
		res += bitget(i, a[i] +oo);
	}
	//cout << bitget1(2, 5);
	//cout << res << endl;
	int q;
	cin >> q;
	long long sum = 0;
	while(q--)
	{
		int id;
		long long s;
		cin >> id >> s;
		s = abs(s + sum)%(2*oo + 1) - oo;
		res -= (bitget(id, a[id] + oo) + bitget1(id, a[id]+oo));
		remove(id, a[id] + oo);
		a[id] += s;
		update(id, a[id] + oo); 
		res += bitget(id, a[id] + oo) + bitget1(id, a[id] + oo);
		cout << res << "\n";
		sum += res;
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
