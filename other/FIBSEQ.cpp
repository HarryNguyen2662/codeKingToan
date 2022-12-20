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

const int maxn = 1e6 + 6;

int n, k, cnt, vit[maxn], ps[maxn], a[maxn]; 
ll st;

struct MATRIX
{
	int c[2][2];
    MATRIX()
    {
        c[0][0] = c[1][0] = c[0][1] = 1; c[1][1] = 0;
    }
   
    MATRIX operator * (const MATRIX &b) const
    {
        MATRIX res , a = *this;
        for(int i=0 ; i<=1 ; ++i) for(int j=0 ; j<=1 ; ++j)
        {
            res.c[i][j] = 0;
            for(int e=0 ; e<=1 ; ++e) 
            {
            	res.c[i][j] += 1ll*a.c[i][e]*b.c[e][j]%k; if (res.c[i][j] >= k) res.c[i][j] -= k;
            }
        }
        return res;
    }

    
};

MATRIX power(ll w)
{
	MATRIX res = MATRIX();
	int e = 0;

	for (int i = 50; i >= 0; i--) if (ck(w, i))
	{
		e = i - 1;	break;
	}   	

	for (; e >= 0; e--)
	{
		res = res*res;
		if (ck(w, e)) res = res*MATRIX();
	}

	return res;

}

int calc(ll e)
{
	if (e <= 2) return 1;
	MATRIX res; res = power(e - 2);
	return (res.c[0][0] + res.c[1][0])%k;
}

void solve() 
{
	cin >> n >> st >> k;

	if (n == 1)
	{
		cout << 1 << " " << st << "\n";
		return;
	}

	cnt++;
	vit[0] = cnt;
	int sum = 0;

	for (int i = 1; i <= n; i++)
	{
		if (i <= 2)
		{
			a[i] = calc(st + i - 1);
		}
		else
		{
			a[i] = a[i - 1] + a[i - 2]; if (a[i] >= k) a[i] -= k;
		}

		sum += a[i]; if (sum >= k) sum -= k;
		 // cout << sum << endl;
		if (vit[sum] == cnt)
		{
			int j = ps[sum];
			cout << i - j << " ";
			for (int e = j + 1; e <= i; e++) cout << st + e - 1 << " ";
			cout << "\n";
			return;
		}
		vit[sum] = cnt; ps[sum] = i;
	}
	cout << "0\n";
}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    // //
    freopen("FIBSEQ.inp","r",stdin); freopen("FIBSEQ.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    cin >> testcase;
    while(testcase--)
        solve();
}
