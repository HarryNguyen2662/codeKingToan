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

int lim, dp[400][2][2][2][8005], lt3[4];
vector<int> L, R;

vector<int> change(const string &s)
{
	vector<int> nu;
	for (int i = 0; i < (int)s.size(); i++) nu.pb(s[i] - '0');
	reverse(ALL(nu));
	vector<int> be;

	while((int)nu.size() != 1 || nu.back() != 0)
	{
		int du = 0;		
		for (int i = (int)nu.size() - 1; i >= 0; i--)
		{
			int va = (du*10 + nu[i]);
			nu[i] = va/3;
			du = va%3;
		}
		be.pb(du);

		while((int)nu.size() > 1 && nu.back() == 0) nu.pop_back();
	}


	return be;
}


int f(int id, int le, int xe, int re, int su)
{
	//cout << id << " " << le << " " << xe << " " << re << " " << su << endl;
	if (id == 0)
	{
		return (xe && su > 0);
	}

	if (dp[id][le][xe][re][su + lim] != -1) return dp[id][le][xe][re][su + lim];

	int &res = dp[id][le][xe][re][su + lim]; res = 0;
	
	int limx = (le == 0 ? L[id - 1] : 0);
	int limy = (re == 0 ? R[id - 1] : 2);

	for (int di = limx; di <= 2; di++) for (int dii = 0; dii <= limy; dii++)
	if (xe == 0 && di <= dii)
	{
		res += f(id - 1, (di == L[id - 1] ? le : 1), (di < dii ? 1 : 0), (dii == R[id - 1] ? re : 1), su + lt3[(id - 1)%4]*(di - dii));
		res %= MOD;
	} 
	else if (xe == 1)
	{
		res += f(id - 1, (di == L[id - 1] ? le : 1), 1, (dii == R[id - 1] ? re : 1), su + lt3[(id - 1)%4]*(di - dii));
		res %= MOD;
	}

	return res;
}

void solve() 
{
	string l, r;
	cin >> l >> r;

	R = change(r); L = change(l);

	while((int)L.size() < (int)R.size()) L.pb(0);

	// for (int i = (int)R.size() - 1; i >= 0; i--) cout << R[i]; cout << endl;
	// for (int i = (int)R.size() - 1; i >= 0; i--) cout << L[i]; cout << endl;


	for (int i = 0; i <= (int)R.size(); i++) for (int e = 0; e < 2; e++) for (int ee = 0; ee < 2; ee++)
		for (int eee = 0; eee < 2; eee++)
		 for (int su = 0; su <= 160*(int)r.size(); su++) dp[i][e][ee][eee][su] = -1;

	lt3[0] = 1; lt3[1] = 3; lt3[2] = 9; lt3[3]= 27;
	lim = 80*(int)r.size();

	cout << f((int)R.size(), 0, 0, 0, 0);
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
