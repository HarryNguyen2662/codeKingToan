#include<bits/stdc++.h>

using namespace std;

#define NMOD 1
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

const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
const long long BASE = 9012005;
const long long MAXN = 100000;
long long pw[NMOD + 1][MAXN + 2];

void preparepw()
{
    for (int i = 0; i < NMOD; i ++)
    {
        pw[i][0] = 1;
        for (int j = 1; j <= MAXN; j++) pw[i][j] = pw[i][j-1]*BASE % HSMOD[i];
    }
}
struct HSS
{   
    int len;
    vector<long long> ps[NMOD];
    HS (const string &s)
    {
        int n = (int)s.size(); len = n;
        for (int i = 0 ; i < NMOD; i ++) 
            {
                ps[i].resize(n + 1);
                ps[i][0] = 0;
                for (int j = 1; j <= n; j++) ps[i][j] = (ps[i][j-1]*BASE + s[j-1])%HSMOD[i];
            }
    } 
    long long qy(int l, int r, int type = 0)
    {
        return (ps[type][r] - ps[type][l-1]*pw[type][r - l + 1] + HSMOD[type]*HSMOD[type])%HSMOD[type];
    }
};

vector<int> id[20];
int len[20];
map<int, int> dp[16390];
map<int, bool> ok[16390];

void solve() 
{
	preparepw();
	string s;
	cin >> s; HSS ldk; ldk.HS(s);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string st;
		cin >> st;
		HSS dk; dk.HS(st); 
		for (int j = 0; j < (int)s.size() - (int)st.size(); j++)
		if (ldk.qy(j + 1, j + (int)st.size()) == dk.qy(1, (int)st.size()))
		id[i].pb(j + 1);
		len[i] = (int)st.size();
		if ((int)id[i].size() == 0)
		{
			cout << 0; return;
		}
	}

	long long res = 0;
	queue<pair<int,long long>> iq;
	dp[0][0] = 1;
	iq.push({0, 0});

	while(!iq.empty())
	{
		int status = iq.front().fi, length = iq.front().se; iq.pop();
		long long val = dp[status][length];
		//cout << __builtin_popcount(status) << " " << status << " " << length << " " << val << endl;

		if (status == mask(n) - 1)
		{
			res = (res + val)%MOD;
			continue;
		}

		for (int i = mask(n)-1-status; i; i ^= (i&(-i)))
		{
			int j = __builtin_ctz(i);
			int vt = upper_bound(ALL(id[j]), length) - id[j].begin();
			if (vt < (int)id[j].size() && id[j][vt] > length)
			{
				//cout << length << " " << len[j] << endl;
				dp[status^mask(j)][id[j][vt] + len[j]-1] = (dp[status^mask(j)][id[j][vt] + len[j]-1] + val)%MOD;
				if (ok[status^mask(j)][id[j][vt] + len[j]-1] == false)
				{
					ok[status^mask(j)][id[j][vt] + len[j]-1] = true;
					iq.push({status^mask(j), id[j][vt] + len[j]-1});
				}
			}
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
