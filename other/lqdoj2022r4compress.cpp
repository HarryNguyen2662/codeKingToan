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

int su[250005], kc[2500005], pe[100], mn[100];
bool dd[250005];

vector<int> ldk[800];

bool cmp(const vector<int> &x, const vector<int> &y)
{
	for (int i = 1; i < (int)x.size(); i++)
	if (x[i] != y[i])
	{
		return x[i] < y[i];
	}
}

void solve() 
{
	int n, k; ll x;
	
	cin >> n >> k >> x;
	
	for (int i = 1; i <= n - k + 1; i++) cin >> su[i];

	for (int i = 1; i <= k; i++)
	{
		mn[i] = 0;
		
		for (int j = i + k; j <= n; j += k)
		{
			kc[j] = kc[j - k] - su[j - k] + su[j - k + 1];
			
			mn[i] = min(mn[i], kc[j]);
		}
		
		pe[i] = i;
	}

	int cnt = 0; ldk[cnt].assign(n + 1, 0);

	do
	{
		// cout << endl;
		// for (int i = 1; i <= k; i++) cout << pe[i] << " "; cout << endl;
		if (1 - mn[pe[1]] <= 0 || 1 - mn[pe[1]] > n) continue;

		vector<int> &a = ldk[cnt];

		int cs = -1;
		int me = 1;	
	
		for (int i = 1; i <= k; i++)
		{
			a[pe[i]] = me - mn[pe[i]]; dd[a[pe[i]]] = true;
			
			for (int j = pe[i] + k; j <= n; j += k)
			{
				a[j] = a[pe[i]] + kc[j];
				
				if (dd[a[j]] == true || a[j] > n)
				{
					cs = i;
					
					a[j] = 0;
					
					break;
				}
				
				dd[a[j]] = true;	
			}
			
			while(dd[me]) me++;

			if (cs != -1 || (i < k && (me - mn[pe[i + 1]] <= 0 || me - mn[pe[i + 1]] > n || dd[me - mn[pe[i + 1]]])))
			{
				cs = i;
				break;
			}

		}

		// cout << cs << endl;
		// for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		if (cs == -1)
		{
			int cur = 0;
			bool kt = true;
			for (int i = 1; i <= n; i++)
			{
				cur += a[i]; if (i > k) cur -= a[i - k];
				if (i >= k && cur != su[i - k + 1])
				{
					kt = false; break;
				}
			}

			if (kt)
			{
				++cnt; ldk[cnt].assign(n + 1, 0);
			}
			
			for (int i = 1; i <= n; i++) dd[i] = false;
		}
		else
		{
			for (int i = 1; i <= cs; i++)
			{
				for (int j = pe[i]; j <= n; j += k) dd[a[j]] = false;
			}
		}

	} while(next_permutation(pe + 1, pe + 1 + k));

	// cout << cnt << endl;

	if (x > cnt)
	{
		cout << "-1\n";
	}
	else
	{
		sort(ldk, ldk + cnt, cmp);

		for (int i = 1; i <= n; i++) cout << ldk[x-1][i] << " "; cout << "\n";
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
    //freopen("COMPRESS.inp","r",stdin); freopen("COMPRESS.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
