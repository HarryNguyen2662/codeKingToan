#include<bits/stdc++.h>

using namespace std;

#define NMOD 3
#define fi first
#define se second
#define pb push_back
#define log 19
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


int n, m;
int dem[500005], cost[500005];
bool ok[500005];


bool kiemtra(int val)
{
	for (int i = 0; i < n; i++) dem[i] = 0;
	for (int i = 0; i < 2*n; i++)
	if (cost[i] >= val)
	{
		dem[max(0, i + val - n)]++; dem[min(n, i + 1)]--;
	}

	if (dem[0] == 0) return false;

	for (int i = 1; i < n; i++)
	{
		dem[i] += dem[i-1];
		if (dem[i] == 0) return false;
	}

	return true;
}

vector<int> lcp_construction(string const& s, vector<int> const& p) 
{
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for (int i = 0; i < n; i++) {
        if (rank[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if (k)
            k--;
    }
    return lcp;
}

void solve() 
{
	cin >> n >> m;
	string s;
	cin >> s;	
	s += s; s += "$";
	int len = (int)s.size();
	for (int i = 1; i <= m; i++)
	{
		string st;
		cin >> st;
		s += st; s += "$";
		for (int j = len; j < len + (int)st.size(); j++) ok[j] = true;
		len += (int)st.size(); len++;
	}

	int nn = (int)s.size();

	vector<int> cn(nn), c(nn), p(nn), pn(nn);
	for (int i = 0; i < nn; i++)
	{
		dem[s[i]]++;
	}

	for (int i = 1; i < 500; i++)
	{
		dem[i] += dem[i-1];
	}

	for (int i = 0; i < nn; i++)
	{
		p[--dem[s[i]]] = i;
	}
	for (int i = 0; i < 500; i++) dem[i] = 0;

	int lever = 0; c[p[0]] = 0;

	for (int i = 1; i < nn; i++) 
	{
		if (s[p[i]] != s[p[i-1]]) lever++; 
		
		c[p[i]] = lever;
	} 


	for (int i = 1; i <= 19; i++)
	{
		for (int j = 0; j < nn; j++)
		{
			pn[j] = p[j] - mask(i - 1); if (pn[j] < 0) pn[j] = (pn[j]%nn + nn)%nn;
			dem[c[pn[j]]]++; p[j] = 0;
		}

		for (int j = 1; j <= lever; j++) dem[j] += dem[j-1];


		for (int j = nn - 1; j >= 0; j--)
		{	
			dem[c[pn[j]]]--;
			p[dem[c[pn[j]]]] = pn[j];
		}

		fill(dem, dem + lever + 1, 0);

		cn[p[0]] = 0;
		lever = 0;

		for (int j = 1; j < nn; j++)
		{
			if (c[p[j-1]] != c[p[j]]
				|| c[(p[j-1] + mask(i - 1))%nn] != c[(p[j] + mask(i - 1))%nn]) lever++;

			cn[p[j]] = lever;
		}
		c.swap(cn);
		if (mask(i) >= nn) break;
	}

	vector<int> lcp = lcp_construction(s, p);

	
	bool okk = false;
	int cur  = 0;

	for (int i = 0; i < nn; i++)
	if (p[i] < 2*n && i > 0)
	{
		if (ok[p[i-1]]) 
		{
			okk = true;
			cur = lcp[i-1];
		}
		else cur = min(lcp[i-1], cur);
		
		if (okk) cost[p[i]] = cur;
	}

	cur = 0;
	okk = false;
	
	for (int i = nn-1; i >=0; i--)
	if (p[i] < 2*n && i + 1 < nn)
	{
		if (ok[p[i+1]]) 
		{
			okk = true;
			cur = lcp[i];
		}
		else cur = min(lcp[i], cur);
		
		if (okk)
		cost[p[i]] = max(cost[p[i]], cur);
	}


	
	int l = 1, r = n;
	while(l <= r)
	{
		int mid = (l + r)/2;
		if (kiemtra(mid)) l = mid + 1; else r = mid - 1;
	}

	cout << r;
}

int main() 
{   
    #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    //freopen("MINSTR.inp","r",stdin); freopen("MINSTR.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
