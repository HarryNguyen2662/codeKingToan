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

int n, m, k, cs[100005];
long long a[100005][15];

bool cmp(const int &x, const int &y)
{
	return a[x][m] < a[y][m];
}

void solve() 
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			a[i][j] += a[i][j-1];
		}
		cs[i] = i;
	}
	long long res =0, luu = 0;;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qe;
	int kk = k%m;
	sort(cs + 1, cs + 1 + n, cmp);
	for (int id = n; id; id--)
	{
		int i = cs[id];
		// cout << i << endl;
		if (k >= m)
		{
			res += a[i][m];
			qe.push({a[i][m] - a[i][kk], i});
			k -= m;
		}
		else if (k > 0)
		{
			res += a[i][k];
			luu = i;
			pair<int,int> w = qe.top();
			if(w.fi < a[i][m] - a[i][kk])
			{
				//cout << "lo" << endl;
				res -= w.fi;
				res += a[i][m] - a[i][kk];
				qe.pop(); qe.push({a[i][m] - a[i][kk], i});
				luu = w.se;
			}
			k = 0;
		}
		else
		{
			//pair<int,int> w = qee.top();
			if(a[luu][(kk)] <= a[i][(kk)])
			{
				res -= a[luu][(kk)];
				res += a[i][(kk)];
				luu = i;
				
				pair<int,int> w = qe.top();
				if(w.fi < a[i][m] - a[i][kk])
				{
					res -= w.fi;
					res += a[i][m] - a[i][kk];
					qe.pop(); qe.push({a[i][m] - a[i][kk], i});
					luu = w.se;
				}
				//qe.push(a[w.se][m] - a[w.se][m - kk]);
			}
		}
	}
	 cout << res;
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
