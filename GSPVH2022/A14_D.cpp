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

pair<char, int> ok[505][505][505];
struct DATA
{
	int fir, sec, thi;
};

void solve() 
{
	string s, st, se;
	cin >> s >> st >> se;


	queue<DATA> que; que.push({0, 0, 0}); ok[0][0][0].fi = 1;

	while(!que.empty())
	{
		int i = que.front().fir, j = que.front().sec, e = que.front().thi; que.pop();
		if (i != 0 ||  j != 0)
		if (i == (int)s.size() && j == (int)st.size())
		{
			vector<char> ans;

			while(ok[i][j][e].se != 0)
			{
				int type = ok[i][j][e].se;
				char w = (char)ok[i][j][e].fi;
				ans.pb(w);
				if (ck(type, 0)) i--;
				if (ck(type, 1)) j--;
				if (ck(type, 2)) e--;
			}

			cout << (int)ans.size() << "\n";
			reverse(ALL(ans));
			for (auto v : ans) cout << v;

			return;
		}

		for (int sl = 0; sl < 2; sl++)
		{
			char w;
			if (sl == 0 && i < (int)s.size()) w = s[i]; else w = st[j];
			int ni = i, nj = j, ne = e;
			if (ni < (int)s.size() && w == s[ni]) ni++;
			if (nj < (int)st.size() && w == st[nj]) nj++;
			if (w == se[ne]) ne++;

			if (ne < (int)se.size() && ok[ni][nj][ne].fi == 0)
			{
				ok[ni][nj][ne] = {w, (ni - i) + (nj - j)*2 + (ne - e)*4};
				que.push({ni, nj, ne});
			}
		}
	}

	cout << "TRETRAU";
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("XCKLT.inp","r",stdin); freopen("XCKLT.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
