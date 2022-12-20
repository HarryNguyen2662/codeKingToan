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

long long power(long long a, long long b)
{
	if (b == 0) return 1;
	long long aa = power(a, b/2);
	if (b%2) return aa*aa%MOD1*a%MOD1; else return aa*aa%MOD1;
}
bool daco[10000005];
int de[10], dd[19487175], te[8];
long long ded[200];
const int lim = mask(7) - 1;
const int spec = (int)1e7;
void solve() 
{
	te[0] = 1;
	for (int i = 1; i <= 6; i++) te[i] = te[i-1]*11;
	int n;
	bool dem = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x; 
		if (daco[x]) 
		{
			cout << 0;
			return;
		}
		daco[x] = true;
		if (x == spec) 
		{
			dem = true;
			continue;
		}
		int sl = 0;
		for (int e = x, j = 1; j <= 7; e /= 10, j++) if (e%10 == 0) sl++;
		de[sl]++;
		for (int j = 0; j < lim; j++) // lim = mask(7) - 1;
		{
			int tt = 0;
			for (int e = x, w = 0; w <= 6; w++, e /= 10) tt += (ck(j, w) ? e%10 : 10)*te[w];
			ded[j] = ded[j] + dd[tt]; dd[tt]++; 
		}
	}
	for (int i = lim - 1; i >= 0; i--)
	{
		for (int j = i; ; j = (j-1)&i)
		{
			//if (j == i) continue;
			if (j != i)
			ded[j] = ded[j] - ded[i];
			if (j == 0) break;
		}
	}
	long long res = 1;
	for (int i = 0; i < lim; i++)  
	{
		//cout << getbit(i) << " " << ded[i] << endl;
		res = res*power(7 - getbit(i), ded[i])%MOD1;
	}
	if (dem) for (int i = 0; i <= 7; i++) res = res*power(8 - i, de[i])%MOD1;
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
    //freopen("numdist.inp","r",stdin); freopen("numdist.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
