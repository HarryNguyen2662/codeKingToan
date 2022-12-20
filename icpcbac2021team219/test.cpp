#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 17
#define getbit1(x) __builtin_popcount(x)
#define mask(i) (1ll << (i))
#define ck(n, i) (((n) >> (i))&1) 
#define setp(x) setprecision(x)
#define NMOD 3
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const long long MOD1 = 998244353;
const long long MODo = 123456789; 
const int oo = 1e9;
const long long oo15= 1e15;
const long long oo18 = 1e18+3;   
const long long oooo = 922372036854775807;
inline int ReadInt()
{
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar());
    int x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    return x;
}
void WriteInt(int x)
{
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}
bool checkpirme(int val)
{
	if (val <= 1) return false;
	for (int i = 2; 1ll*i*i <= val; i++) if (val%i == 0) return false;
	return true;
}
long long n, res = 0;
bool prime[10000];
vector<int> ldk;
void trau(int id, long long val, int sum, int x)
{
	//kt[val] = true;
	//cout << val << endl;
	//cout << val << endl;
	if (id == 15)
	{
		//cout << val << endl;
		if (val <= n && sum == x)
		ldk.pb(val);
		return;
	}
	//if (id == 15) return;
	for (int i = 0; i <= 9; i++) if (val*10 + i <= n && sum + i <= x) trau(id + 1, val*10 + i, sum + i, x);

}
void solve()
{
	cin >> n;
	for (int i = 2; i <= 135; i++) if (checkpirme(i)) prime[i] = true, trau(0, 0, 0, i);
	//for (auto v : prime) cout << v << " ";
	//trau(0, 0, 0, 2);
	cout << ldk.size() << endl;
	cout << res;
}	
int main()
{   
    #ifndef ONLINE_JUDGE
    freopen("hihiinp.txt","r",stdin);
    freopen("hihiout.txt","w",stdout);
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
