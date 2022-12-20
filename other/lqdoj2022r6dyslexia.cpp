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

const char B64[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int position[256];
void initBase64(){
    for (int i = 0; i < 64; i++)
        position[B64[i]] = i;
}

#define MAX 10000001
int n;
char s[MAX]; 
void b64Conversion(const string &S){
    int ptr = 0;
    for (char c: S){
        int x = position[c];
        for (int i = 0; i < 6; i++){
            s[++ptr] = (x & 1) + '0';
            x >>= 1;
        }
    }
}

void solve() 
{
	int n;
	cin >> n; 
	string st;
	cin >> st;
	b64Conversion(st);

	ll ans = 0;
	ll cur = 0;
	ll su = 0;
	ll len = 0;

	for (int i = 1; i <= n; i++) 
	{
		if (s[i] == '0')
		{
			ans += 1ll*(n - i + 1)*cur%MOD; if (ans >= MOD) ans -= MOD;
		}

		cur += i*(s[i] - '0'); if (cur >= MOD) cur -= MOD;

		if (s[i] != s[i - 1])
		{
			su = 1; len = 1;
			ans ++; if (ans >= MOD) ans -= MOD;
		}
		else
		{
			len++; 
			ans += su + 1ll*len*len%MOD; while (ans >= MOD) ans -= MOD;
			su += 1ll*len*len%MOD; if (su >= MOD) su -= MOD; 
		}

	}

	cur = 0;

	for (int i = n; i >= 1; i--) 
	{
		if (s[i] == '0')
		{
			ans += 1ll*i*cur%MOD; if (ans >= MOD) ans -= MOD;
		}

		cur += (n - i + 1)*(s[i] - '0'); if (cur >= MOD) cur -= MOD;

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
    //freopen("DYSLEXIA.inp","r",stdin); freopen("DYSLEXIA.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    initBase64();
    //cin >> testcase;
    while(testcase--)
        solve();
}
