#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define ll long long
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

ll d[3000005];

void solve() 
{
	int n, h;
	cin >> h >> n;
	for (int i = 1; i <= n; i++)
	{
		int u, v;
		cin >> u >> v;
		ll ltu = 0, lmau = 1, rtu = 1, rmau = 0;
		d[i] = 1;

		while((ltu + rtu) != u || (lmau + rmau) != v)
		{
			ll cu = (ltu + rtu), cuu = (lmau + rmau);
			d[i] *= 2;
			if (cu*v > u*cuu)
			{
				rtu = cu; rmau = cuu;
			}
			else
			{
				d[i]++;
				ltu = cu; lmau = cuu;	
			}
		}
	}

	sort(d + 1, d + 1 + n);
	//for (int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;

	int id = n;

	deque<ll> q;

	ll ans = 0;
	
	while(id || !q.empty())
	{

		//cout << id << " " << id1 << " " << cnt << endl;

		while(id && d[id] == 1) id--;
		while(id > 1 && d[id] == d[id-1]) id--;

		while(id && !q.empty() && d[id] == q.front())
		{
			id--;
		}

		if (id && !q.empty())
		{
			if (d[id] > q.front())
			{
				if (d[id]/2 != 1 && d[id]/2 != q.back())
				q.push_back(d[id]/2);
				id--;
			}
			else
			{
				if (q.front()/2 != 1 && q.front()/2 != q.back())
				q.push_back(q.front()/2);
				q.pop_front();
			}
			ans++;
		}
		else if (id)
		{
			if (d[id]/2 != 1)
			q.push_back(d[id]/2);
			id--;
			ans++;

		}
		else if (!q.empty())
		{
			if (q.front()/2 != 1 && q.front()/2 != q.back())
			q.push_back(q.front()/2);
			q.pop_front();
			ans++;
		}

	}

	cout << ans;
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
