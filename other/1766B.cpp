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
const ll base = 9012005;
bool ok[200005];
ll hs[200005], pw[200005];

map<ll, bool> dd;

void solve() 
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if ((int)s.size() < n)
	{
		cout << "YES\n"; return;
	}

	if (n == 1 && (int)s.size() >= 1)
	{
		cout << "NO\n"; return;
	}
	int m  = s.size();

	
	int dem = 0;

	int sl = 3;

	pw[0] = 1;

	for (int i = 0; i < m; i++)
	{
		hs[i + 1] = hs[i]*base + s[i];
		pw[i + 1] = pw[i]*base;
		ok[i] = false;
	}


	for (int i = 0; i < m; i++)
	{
		if (ok[i] == true)
		{
			for (int j = max(0, i - sl); j <= i; j++) dd[hs[i + 1] - hs[j]*pw[i - j + 1]] = true;
			continue;
		}
		int cur = 0;
		dem++;
		while(true)
		{
			if (i + cur == m) 
			{
				cur++;
				break;
			}
			if (dd[hs[i + cur + 1] - hs[i]*pw[cur + 1]] == false) 
			{
				break;
			}
			cur++;
		}
		if (cur)
		for (int j = i + 1; j <= i + cur - 1; j++) ok[j] = true;
		
		for (int j = max(0, i - sl); j <= i; j++) dd[hs[i + 1] - hs[j]*pw[i - j + 1]] = true;
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = max(0, i - sl); j <= i; j++) dd[hs[i + 1] - hs[j]*pw[i - j + 1]] = false;
	}
	if (dem < n) cout << "YES\n"; else cout << "NO\n";

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
    cin >> testcase;
    while(testcase--)
        solve();
}
