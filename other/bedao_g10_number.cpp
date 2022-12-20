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

int a[300005];

void solve() 
{
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	sort(a + 1, a + 1 + n);
	n = unique(a + 1, a + 1 + n);
	while(n > 1 && a[n] == a[n - 1]) n--;

	for (int i = 0; i < a[1]; i++) dist[i] = oo;
	dist[0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; pq.push({0, 0});

	while(!pq.empty())
	{
		int val = pq.top().se, dis = pq.top().fi; pq.pop();

		if (dist[val] != dis) continue;

		for (int i = 2; i <= n; i++)
		{
			int nval = (val + a[i])%a[1];

			if (dist[nval] > dis + a[i])
			{
				dist[nval] = dis + a[i]; pq.push({dist[nval], nval});
			}
		}
	}

	for (int i = 0; i < a[1]; i++)
	{
		cs[i] = i;
	}

	sort(cs, cs + a[1], [](const int &x, const int &y)
	{
		return dist[x] < dist[y];
	});

	for (int i = 1; i <= q; i++)
	{
		cin >> luu[i].fi; luu[i].se = i;
	}

	sort(luu + 1, luu + 1 + q);

	int l = 0;

	update()

	ll su = dist[cs[0]]/a[1];

	for (int i = 1; i <= q; i++)
	{
		while(l + 1 < a[1] && dist[cs[l + 1]] <= luu[i].fi)
		{
			l++; su += dist[cs[l]]/a[1];
		adu.update()
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
