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
typedef pair<int, int> DATA;

int dem[100005];

DATA a[100005];

int ans[100005];

vector<int> ed[100005];

void solve() 
{
	set<DATA> ss;
	int n, k, m;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].fi >> a[i].se;
		ed[a[i].fi].pb(a[i].se); ed[a[i].se].pb(a[i].fi);
		dem[a[i].fi]++; dem[a[i].se]++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		ss.insert({dem[i], i});
	}
	
	for (int i = m; i; i--)
	{
		while(!(int)ss.size())
		{
			DATA u = *ss.begin(); 
			if (u.fi >= k) break;
			cout << "helloo " << endl;
			ss.erase(u);
			for (auto v : ed[u.se]) 
			{
				dem[u.se]--;
				if (dem[v] >= k)
				{
					DATA ne = {dem[v], v};
					ss.erase(ne);
					dem[v]--;
					ss.insert({dem[v], v});
				}
			} 
		}
		ans[i] = (int)ss.size();
		ed[a[i].fi].pop_back(); 
		if (dem[a[i].fi] == k)
				{
					DATA ne = {dem[a[i].fi], a[i].fi};
					ss.erase(ne);
					dem[a[i].fi]--;
					for (auto v : ed[a[i].fi]) 
					if (dem[v] >= k)
					{
						DATA ne = {dem[v], v};
						ss.erase(ne);
						dem[v]--;
						ss.insert({dem[v], v});
					}			
				}
		else if (dem[a[i].fi] > k)
		{
			DATA ne = {dem[a[i].fi], a[i].fi}; dem[a[i].fi]--;
			ss.erase(ne); ss.insert({dem[a[i].fi], a[i].fi});
		}
		ed[a[i].se].pop_back();
		if (dem[a[i].se] == k)
				{
					DATA ne = {dem[a[i].se], a[i].se};
					ss.erase(ne);
					dem[a[i].se]--;
					for (auto v : ed[a[i].se]) 
					if (dem[v] >= k)
					{
						DATA ne = {dem[v], v};
						ss.erase(ne);
						dem[v]--;
						ss.insert({dem[v], v});
					}		
				}
		else if (dem[a[i].se] > k)
		{
			DATA ne = {dem[a[i].se], a[i].se}; dem[a[i].se]--;
			ss.erase(ne); ss.insert({dem[a[i].se], a[i].se});
		}
	}

	for (int i = 1; i <= m; i++) cout << ans[i] << "\n";
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
