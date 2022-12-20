#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
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

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

map<ll, bool> dd;
ll a[500005], b[3000005];

void solve() 
{
	priority_queue<ll> qe;
	ll k, h, n;
	k = read_int(); h = read_int(); n = read_int();
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		ll cur;
		cur = read_int();
		if (dd[cur] == false)
		{
			dd[cur] = true;
			a[++cnt] = cur;
		}
	}

	sort(a + 1, a + 1 + cnt);
	int id = 1, cmt = 0;
	ll res = 0;

	while(true)
	{
		while(cnt && id <= cmt && a[cnt] == b[id]) id++; 

		if ((cnt == 0 && id == cmt) || (id > cmt && cnt == 1))
		{
			break;
		}

		res++; 
		if (cnt && id <= cmt)
		{
			if (a[cnt] > b[id])
			{
				ll nw = (a[cnt] + k - 2)/k; cnt--;
				if (b[cmt] != nw) b[++cmt] = nw;
			}
			else
			{
				ll nw = (b[id] + k - 2)/k; id++;
				if (b[cmt] != nw) b[++cmt] = nw;
			}
		}
		else if (cnt)
		{
			ll nw = (a[cnt] + k - 2)/k; cnt--;
			if (b[cmt] != nw) b[++cmt] = nw;
		}
		else
		{
			ll nw = (b[id] + k - 2)/k; id++;
			if (b[cmt] != nw) b[++cmt] = nw;
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
