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
int n;
vector<pair<int,int>> ldk[500005], qa[500005];
int suf1[500005], suf2[500005], a[500005], fen[500005], fen1[500005];
void update(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen[id] += val;
}
int get(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen[id];
	return res;
}
void update1(int id, int val)
{
	for (; id <= n; id += (id&(-id))) fen1[id] += val;
}
int get1(int id)
{
	int res = 0;
	for (; id; id -= (id&(-id))) res += fen1[id];
	return res;
}
void solve() 
{	
	stack<int> st, stt;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int pre1, pre2;
		cin >> a[i];
		while(!st.empty() && a[st.top()] < a[i]) st.pop();
		if (st.empty()) pre1 = 0; else pre1 = st.top();
		st.push(i);
		if (pre1 + 1 < i) 
		{
			//cout << pre1 << " " << i << endl;
			ldk[pre1+1].pb({i, 1});
			ldk[i].pb({i, -1});
		}
		while(!stt.empty() && a[stt.top()] > a[i]) stt.pop();
		if (stt.empty()) pre2 = 0; else pre2 = stt.top();
		stt.push(i);
		if (pre2 + 1 < i)
		{
			qa[pre2+1].pb({i, 1});
			qa[i].pb({i, -1});
		}
	}
	while(!stt.empty()) stt.pop();
	while(!st.empty()) st.pop();
	for (int i = n; i; i--)
	{
		while(!st.empty() && a[st.top()] < a[i]) st.pop();
		if (st.empty()) suf1[i] = n+1; else suf1[i] = st.top();
		st.push(i);
		while(!stt.empty() && a[stt.top()] > a[i]) stt.pop();
		if (stt.empty()) suf2[i] = n+1; else suf2[i] = stt.top();
		stt.push(i);
	}
	long long res = 0;
	for (int i = 1; i <= n; i++)
	{
		for(auto v : ldk[i]) update(v.fi, v.se);
		//cout << get(suf2[i] - 1) << endl;
		res += get(suf2[i] - 1);
		for (auto v : qa[i]) update1(v.fi, v.se);
		res += get1(suf1[i] - 1);
	}
	cout << res + n;
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
