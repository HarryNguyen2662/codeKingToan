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

vector<int> fpre[300005], fsuf[300005];
int a[300005], b[300005], pre[300005], pre1[300005], suf[300005], suf1[300005];
long long lazy[1200005], sg[1200005];

void dolazy(int id)
{
	for (int i = id*2 ; i <= id*2+1; i++)
	{
		sg[i] = max(sg[i], lazy[id]); 
		lazy[i] = max(lazy[i], lazy[id]);
	}
	lazy[id] = -oo18;
}

void update(int id, int l, int r, int u, int v, long long val)
{
	if (r < u || l > v) return;
	if (u <= l && r <= v)
	{
		sg[id] = max(sg[id], val);
		lazy[id] = max(lazy[id], val);
		return; 
	}
	int mid = (l + r)/2;
	dolazy(id);
	update(id*2, l, mid, u, v, val); update(id*2 + 1, mid + 1, r, u, v, val);
	sg[id] = max(sg[id*2], sg[id*2 + 1]);
}

long long get(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return -oo18;
	if (u <= l && r <= v)
	{
		return sg[id];
	}
	int mid = (l + r)/2;
	dolazy(id);
	return max(get(id*2, l, mid, u, v), get(id*2+1, mid+1, r, u, v));
}

void solve() 
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; 
	} 
	for (int i = 1; i <= 4*n; i++) lazy[i] = sg[i] = -oo18;
	stack<int> inst;
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
		while(!inst.empty() && b[inst.top()] <= b[i]) inst.pop();
		if (!inst.empty()) 
		{
			pre[i] = inst.top(); 
			fpre[inst.top()].pb(i); 
		}
		inst.push(i);
	}
	
	vector<int> ldk;
	for (int i = 1; i < n; i++)
	if (b[i] != b[i+1])
	{
		while(!ldk.empty() && b[ldk.back()] <= b[i]) ldk.pop_back();
		ldk.pb(i);
		if (b[i] > b[i+1])
		{
			for (auto v : fpre[i+1]) pre1[v] = i;
		}
		else
		{
			for (auto v : fpre[i+1])
			{
				int l = 0, r = (int)ldk.size()-1;
				while(l <= r)
				{
					int mid = (l + r)/2;
					if (b[ldk[mid]] > b[v])
					l = mid + 1;
					else r = mid - 1;
				}	
				if (r != -1) pre1[v] = ldk[r];
			}
		}
	}

	ldk.clear(); while(!inst.empty()) inst.pop();
	for (int i = n; i; i--)
	{
		while(!inst.empty() && b[inst.top()] <= b[i]) inst.pop();
		if (!inst.empty()) 
		{
			suf[i] = inst.top(); 
			fsuf[inst.top()].pb(i); 
		} else suf[i] = n + 1;
		suf1[i] = n + 1;
		inst.push(i);
	}
	
	for (int i = n; i > 1; i--)
	if (b[i] != b[i-1])
	{
		while(!ldk.empty() && b[ldk.back()] <= b[i]) ldk.pop_back();
		ldk.pb(i);
		if (b[i] > b[i-1])
		{
			for (auto v : fsuf[i-1]) suf1[v] = i;
		}
		else
		{
			for (auto v : fsuf[i-1])
			{
				int l = 0, r = (int)ldk.size()-1;
				while(l <= r)
				{
					int mid = (l + r)/2;
					if (b[ldk[mid]] > b[v])
					l = mid + 1;
					else r = mid - 1;
				}	
				if (r != -1) suf1[v] = ldk[r];
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		long long val = a[i];
		if (pre[i] > 0)
		{
			if (pre1[i] > 0) val = get(1, 1, n, pre1[i], pre[i] - 1) + a[i];
			else if (pre[i] > 1) val = max(0ll, get(1, 1, n, 1, pre[i] - 1)) + a[i];
			update(1, 1, n, i, suf[i] - 1, val);
		}
		val = a[i];
		if (suf[i] <= n)
		{
			if (pre[i] > 0) val = get(1, 1, n, pre[i], i - 1) + a[i];
			else if (i > 1) val = max(0ll, get(1, 1, n, 1, i - 1)) + a[i];
			update(1, 1, n, suf[i], suf1[i] - 1, val);
		}
	}
	cout << get(1, 1, n, n, n);

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
