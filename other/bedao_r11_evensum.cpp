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

int sg[400005];
bool laz[400005];

void dolaz(int id, int l, int mid, int r)
{
	if (laz[id] == 0) return;

	sg[id*2] = mid - l + 1 - sg[id*2]; laz[id*2] = 1 - laz[id*2];

	sg[id*2+1] = r - mid - sg[id*2 + 1]; laz[id*2 + 1] = 1 - laz[id*2 + 1];

	laz[id] = 0;
}

void update(int id, int l, int r, int u, int v)
{
	if ( r < u || l > v) return;

	if (u <= l && r <= v)
	{
		sg[id] = r - l + 1 - sg[id];
		laz[id] = 1 - laz[id];
		return;
	}
	int mid = (l + r)/2;
	dolaz(id, l, mid, r);

	update(id*2, l, mid, u, v); update(id*2+1, mid + 1, r, u, v);

	sg[id] = sg[id*2] + sg[id*2+1] ;
}

int get(int id, int l, int r, int u, int v)
{
	if (r < u || l > v) return false;
	if (u <= l && r <= v)
	{
		return sg[id];
	}

	int mid = (l + r)/2;
	dolaz(id, l, mid, r);

	return get(id*2, l, mid, u, v) + get(id*2+1, mid + 1, r, u, v);
}

int a[100005];

void solve() 
{
	int n, q;
	long long su = 0;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];

		su += a[i];
	
		if (su%2) update(1, 1, n, i, i);	
	}

	while(q--)
	{
		int type, l, r;
		cin >> type >> l >> r;

		if (type == 1)
		{
			if (a[l]%2 != r%2)
			{
				update(1, 1, n,l, n);
			}

			a[l] = r;
		}
		else
		{
			int sl = get(1, 1, n, max(1, l - 1), r);
			int sl1 = r - l + 2 - sl;

			cout << 1ll*sl*(sl-1)/2 + 1ll*sl1*(sl1-1)/2 << "\n";
		}
		
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
