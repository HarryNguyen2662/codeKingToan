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
int st[1300000];
int a[300005], n;
long long fen1[300005], fen2[300005];
void update1(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen1[id] += val;
}
void update2(int id, int val)
{
	for (; id; id -= (id&(-id))) fen2[id] += val;
}
long long get1(int id)
{
	long long res = 0;
	for (; id; id -= (id&(-id))) res += fen1[id];
	return res;
}
long long get2(int id)
{
	long long res = 0;
	for (; id <= n; id += (id&(-id))) res += fen2[id];
	return res;
}
void build(int id, int l, int r)
{
	if (l == r)
	{
		st[id] = 1;
		return;
	}
	int mid = (l + r)/2;
	build(id*2, l , mid); build(id*2+1, mid + 1, r);
	st[id] = st[id*2] + st[id*2+1];
}
void update(int id, int l, int r, int i)
{
	if (l > i || r < i) return;
	if (l == r)
	{
		st[id] = 0;
		return;
 	}
 	int mid = (l + r)/2;
 	if (mid >= i) update(id*2, l, mid, i); else update(id*2+1, mid + 1, r, i);
	st[id] = st[id*2] + st[id*2+1];	
}
int get(int id, int l, int r, int va)
{
	if (l == r)
	{
		//if (st[id*2].fi == va) break;
		return l;
	}
	int mid = (l + r)/2;
	if (va <= st[id*2]) return get(id*2, l, mid, va);
	else return get(id*2 + 1, mid + 1, r, va - st[id*2]);
}
void solve() 
{	
	//int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	build(1, 1, n);
	for (int i = 1; i <= n; i++)
	{
		update1(i, a[i]);
		update2(i, a[i]);
	}
	for (int i = n; i; i--)
	{
		int id = get(1, 1, n, (i+1)/2);
		cout << get2(id+1) - get1(id) + 1ll*(2*((i+1)/2) - i)*a[id] << " ";
		update(1, 1, n, id);
		update1(id, -a[id]);
		update2(id, -a[id]);
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
