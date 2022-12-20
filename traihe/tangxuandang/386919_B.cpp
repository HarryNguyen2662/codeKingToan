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

int a[5000005], luu[5000005], pre[5000005];

void solve() 
{
	int n;
	cin >> n;
	int cnt = 0, cmt = 0;
	int id = 0;
	vector<int> ldk;
	while(n--)
	{
		id++;
		int type;
		cin >> type;
		if (type == 0)
		{	
			ldk.pb(id);
			cout << a[luu[cmt]] << "\n";
		}
		else if (type == 1)
		{
			cmt++;
			luu[cmt] = ++cnt; cin >> a[cnt];
			pre[cnt] = luu[cmt-1];
		}
		else if (type == 2)
		{
			cmt++;
			//cout << luu[cmt-] << endl;
			luu[cmt] = pre[luu[cmt-1]];
		}
		else
		{
			int x;
			cin >> x;
			cmt++;
			x -=  (upper_bound(ALL(ldk), x) - ldk.begin());
			luu[cmt] = luu[x]; 
		}
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
