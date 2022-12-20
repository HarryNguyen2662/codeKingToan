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



long long wg[2000005], tot[500005], ww[2000005], w[2000005];
long long sg[2000005], lazy[2000005];

void build(int id, int l, int r)
{
	lazy[id] = MOD1-1;
	if (l == r)
	{
		sg[id] = MOD1-1;
		wg[id] = ((MOD1-1)*(tot[l] - tot[l-1] + MOD1)%MOD1 + MOD1)%MOD1;
		//cout << wg[id] << endl;
		w[id] = wg[id];
		ww[id] = (tot[l] - tot[l-1] + MOD1)%MOD1;
		return;
	}

	int mid = (l + r)/2;
	build(id*2, l, mid); build(id*2+1, mid + 1, r);
	sg[id] = min(sg[id*2], sg[id*2+1]);
	if (sg[id*2] == sg[id*2+1])
	{
		ww[id] = (ww[id*2] + ww[id*2+1])%MOD1;
		w[id] = (w[id*2] + w[id*2+1])%MOD1;
	}
	else if (sg[id*2+1] > sg[id*2])
	{
		w[id] = w[id*2]; ww[id] = ww[id*2];
	}
	else 
	{
		w[id] = w[id*2+1]; ww[id] = ww[id*2+1];
	}
	wg[id] = (wg[id*2] + wg[id*2+1])%MOD1;

}

void dolazy(int id, int l, int r)
{
	long long val = lazy[id];
	if (val == MOD1-1) return;
	int mid = (l + r)/2;
	
	lazy[id*2] = min(lazy[id*2], val);
	if (sg[id*2] >= val)
	{
		sg[id*2] = val;
		wg[id*2] = 1ll*val*(tot[mid] - tot[l-1] + MOD1)%MOD1;
		w[id*2] = wg[id*2]; ww[id*2] = (tot[mid] - tot[l-1] + MOD1)%MOD1;
	}
	else
	{
		wg[id*2] = 1ll*val*(tot[mid] - tot[l-1] + MOD1)%MOD1;
		wg[id*2] = ((wg[id*2] - 1ll*val*ww[id*2]%MOD1 + MOD1)%MOD1 + w[id*2])%MOD1;
	}

	lazy[id*2+1] = min(lazy[id*2+1], val);
	if (sg[id*2+1] >= val)
	{
		sg[id*2+1] = val;
		wg[id*2+1] = 1ll*val*(tot[r] - tot[mid] + MOD1)%MOD1;
		w[id*2+1] = wg[id*2+1]; ww[id*2+1] = (tot[r] - tot[mid] + MOD1)%MOD1;
	}
	else
	{
		wg[id*2+1] = 1ll*val*(tot[r] - tot[mid] + MOD1)%MOD1;
		wg[id*2+1] = ((wg[id*2+1] - 1ll*val*ww[id*2+1]%MOD1 + MOD1)%MOD1 + w[id*2+1])%MOD1;
	}

	lazy[id] = MOD1-1;
}	

void update(int id, int l, int r, int u, int v, long long val)
{
	if (l > v || r < u) return;
	
	
	if (u <= l && r <= v)
	{
		lazy[id] = min(lazy[id], val);
		if (sg[id] >= val)
		{
			sg[id] = val;
			wg[id] = 1ll*val*(tot[r] - tot[l-1] + MOD1)%MOD1;
			w[id] = wg[id];
			ww[id] = (tot[r] - tot[l-1] + MOD1)%MOD1;
			
		}
		else
		{
			wg[id] = 1ll*val*(tot[r] - tot[l-1] + MOD1)%MOD1;
			wg[id] = ((wg[id] - 1ll*val*ww[id]%MOD1 + MOD1)%MOD1 + w[id])%MOD1;

		}
		return;
	}
	
	int mid = (l + r)/2;
	
	dolazy(id, l, r);
	
	update(id*2, l, mid, u, v, val); update(id*2+1, mid+1, r, u, v, val);
	
	sg[id]  =  min(sg[id*2], sg[id*2+1]);
	
	if (sg[id*2] == sg[id*2+1])
	{
		ww[id] = (ww[id*2] + ww[id*2+1])%MOD1;
		w[id] = (w[id*2] + w[id*2+1])%MOD1;
	}
	else if (sg[id*2] > sg[id*2+1])
	{
		w[id] = w[id*2+1]; ww[id] = ww[id*2+1];
	}
	else 
	{
		w[id] = w[id*2]; ww[id] = ww[id*2];
	}
	
	wg[id] = (wg[id*2] + wg[id*2+1])%MOD1;
	//cout << id << " " << wg[id] << endl;
}
 

int getmin(int id, int l, int r, int u, int v)
{ 
	if (l > v || r < u) return MOD1-1;

	if (u <= l && r <= v)
	{
		return sg[id];
	}
	int mid = (l + r)/2;
	dolazy(id, l, r);
	return min(getmin(id*2, l, mid, u, v), getmin(id*2+1, mid + 1, r, u, v));
}

void solve() 
{
	int n, k, m;
	cin >> n;
	cin >> n >> k >> m;
	long long w = 1; tot[0] = 1;
	for (int i =1 ; i <= n; i++) 
	{
		w = w*1ll*(n+1)%MOD1;
		tot[i] = (tot[i-1] + w)%MOD1;
	}
	build(1, 1, n);
	for (int i = 1; i <= k; i++)
	{
		int x;
		cin >> x;
		update(1, 1, n, x, x, 0);
		//cout << endl;
	}
	cout << wg[1] << "\n";

	while(m--)
	{
		char type; int l, r;
		cin >> type >> l >> r;
		
		if (type == 'D')
		{
			int w1 = getmin(1, 1, n, l, l);
			int w2 = getmin(1, 1, n, r, r);
			w1 = min(w1, w2);
			if (w1 != MOD-1)
			{
				update(1, 1, n, r, r, w1 + 1);
				update(1, 1, n, l, l, w1 + 1);
			}
		}
		else 
		{
			int w = getmin(1, 1, n, l, r);
			if (w != MOD1-1)
			update(1, 1, n, l, r, w + 1);
	
			
		}
		cout << wg[1] << "\n";
	}
}	

int main() 
{   
    freopen("COVID19.inp","r",stdin); freopen("COVID19.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
