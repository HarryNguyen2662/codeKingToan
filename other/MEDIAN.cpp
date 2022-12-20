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

class fenwicktree {
private:
    int len;
    vector<int> fen;
 
public:
    void reset(int sz) {
    	fen.assign(sz + 3, 0);
        len = sz;
    }
 	
 	int sz()
 	{
 		return len;
 	}

    void update(int id, int val)
    {
    	for (; id <= len; id += (id&(-id))) fen[id] += val;
    }

	int get(int id)
	{
		int res = 0;
		for (; id; id -= (id&(-id))) res += fen[id];
		return res;
	}
} ;
int cnt = 0;
fenwicktree dk;
int find(int val)
{
	val--;
	int l = 1, r = (int)dk.sz();

	while(l <= r)
	{
		int mid = (l + r)/2;
		if (dk.get(mid) > val) r = mid - 1; else l = mid + 1;
	}
	return l;
}

pair<int, long long> luu[5000005];

void solve() 
{
	int q;
	vector<long long> ldk;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		string s; long long val;
		cin >> s ;
		if (s == "IN") 
		{
			cin >> val;
			luu[i] = {0, val};
			ldk.pb(val);	
		}
		else if (s == "OUT")
		{
			cin >> val;
			luu[i] = {1, val};
		}
		else luu[i] = {2, 0};
	}
	sort(ALL(ldk)); ldk.resize(unique(ALL(ldk)) - ldk.begin());

	int n = (int)ldk.size();

	 dk.reset(n);

	for (int i = 1; i <= q; i++)
	if (luu[i].fi == 0)
	{
		cnt++;
		int val = lower_bound(ALL(ldk), luu[i].se) - ldk.begin() + 1;
		dk.update(val, 1);
	}
	else if (luu[i].fi == 1)
	{
		cnt--;
		int val = lower_bound(ALL(ldk), luu[i].se) - ldk.begin() + 1;
		dk.update(val, -1);
	}
	else
	{		
		int id = find(cnt/2 + 1) - 1, id1 = id;
		if (cnt%2 == 0) id = find(cnt/2) - 1;
		cout << (ldk[id] + ldk[id1])/2; if ((ldk[id] + ldk[id1])%2) cout << ".5";
		cout << "\n";
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
