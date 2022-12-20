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

map<int,int> dd;
int dem[4];
int a[200005], id[4];

void solve() 
{	
	int n, m;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dem[a[i]%2]++;
		dd[a[i]]++;
	}

	id[0] = 2; id[1] = 1;

	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		if (dd[a[i]] > 1)
		{
			dem[a[i]%2]--; dd[a[i]]--;
			int ti = (a[i]%2 + (dem[a[i]%2] > dem[1 - a[i]%2]))%2;
			while(id[ti] < m && dd[id[ti]]) id[ti] += 2;
			if (id[ti] > m || dd[id[ti]])
			{
				cout << "-1\n";
				return;
			}
			a[i] = id[ti]; dd[a[i]]++; dem[a[i]%2]++;
			res++;
		}
	}

	if (dem[0] != dem[1])
	{
		int ti = 1 - (dem[1] > dem[0]);

		for (int i = 1; i <= n; i++)
		if (a[i]%2 == 1 - ti)
		{
			dem[a[i]%2]--; dd[a[i]]--;
			while(id[ti] < m && dd[id[ti]]) id[ti] += 2;
			if (id[ti] > m || dd[id[ti]])
			{
				cout << "-1\n";
				return;
			}
			a[i] = id[ti]; dd[a[i]]++; dem[a[i]%2]++;
			res++;
			if (dem[1] == dem[0])
			{
				break;
			}
		}
	}

	cout << res << "\n"; for (int i = 1; i <= n; i++) cout << a[i] << " ";

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
