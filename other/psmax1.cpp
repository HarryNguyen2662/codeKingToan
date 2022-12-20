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


bitset<200> c[1000];

bitset<200> basis[205];


void insertVector(bitset<200> &msk) {
	for (int i = 199; i >= 0; i--) {
		if (msk[i] == 0) continue;

		if (basis[i] == 0) {
			basis[i] = msk;
			return;
		}

		msk ^= basis[i];
	}
}

 
void solve() 
{
	auto checkprime = [&](const int &val)
	{
		if (val <= 1) return false;
 
		for (int i = 2; i*i <= val; i++) if (val%i == 0) return false;
 
		return true;
	};
 
	vector<int> prime; for (int i = 2; i <= 1000; i++) if (checkprime(i)) prime.pb(i);
 
	int n;
	cin >> n;
 
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		for (int j = 0; j < 168; j++)
		{
			while(val%(prime[j]*prime[j]) == 0) val /= (prime[j]*prime[j]);
			if (val%prime[j] == 0) c[i][j] = 1;
		}
		insertVector(c[i]);
	}

	int res = 0;
 
	for (int i = 0; i < 200; i++)
	if (basis[i] != 0)
	{
		res ++;
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
