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

vector<double> clm[4005];
pair<int,int> a[4005];

double cal(int i, int j)
{
	long long val = 1ll*(a[i].fi - a[j].fi)*(a[i].fi - a[j].fi) +  1ll*(a[i].se - a[j].se)*(a[i].se - a[j].se);
	return (double)sqrt(val);
}
int dem[4005];
void solve() 
{
	vector<pair<double, pair<int,int>>> ldk;
	int n;
	cin >> n;
	vector<int> dm;
	for (int i = 1; i <= n; i++)
	{
		dm.pb(i);
		cin >> a[i].fi >> a[i].se;
	}
	for (int i = 1 ; i <= n; i++) for (int j = i; j <= n; j++) 
	{
		ldk.pb({cal(i, j), {i, j}});
	}
	sort(ALL(ldk));
	int st = (int)ldk.size() - 1;
	for (int i = (int)ldk.size() - 1;  i >= 0; i--)
	{
		//cout <<"lo " <<  ldk[i].fi << " " << ldk[i].se.fi << " " << ldk[i].se.se << endl;
		if(i != (int)ldk.size() - 1 && ldk[i].fi != ldk[i+1].fi)
		{
				for (int j = (int)dm.size() - 1; j >= 0; j--)
				if (st - i > dem[dm[j]])
				{
			//		dem[dm[j]] = false;
					//cout << dm[j] << " " << dem[dm[j]] << endl;
					clm[dm[j]].pb(ldk[i+1].fi);
					if ((int)clm[dm[j]].size() == 2) 
					{
						swap(dm[j], dm.back()); dm.pop_back();
					}
				}
				if (dm.empty()) break;
			for (int j = st; j > i; j--) dem[ldk[j].se.fi] = dem[ldk[j].se.se] = 0;
			st = i;
		}
		dem[ldk[i].se.fi] ++; dem[ldk[i].se.se] ++;

	}
	//cout << endl;
	cout << fixed << setp(9);
	for (int i = 1; i <= n; i++) cout << clm[i][1] << "\n";

}

int main() 
{   
    
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("euclid.inp","r",stdin); freopen("euclid.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
