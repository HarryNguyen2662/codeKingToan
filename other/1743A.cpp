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

string ss[100];

void solve() 
{
	int n;
	int id = -1;
	cin >> n;
	string s;
	cin >> s;
	bool ok = false;
	reverse(ALL(s)); while((int)s.size() > 1 && s.back() == '0') 
	{
		ok = true;
		s.pop_back(); 
		n--;
	}
	reverse(ALL(s));

	if (s.size() == 1 && s == "0")
	{
		cout << "0"; return;
	}
	int cnt = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			id = i; break;
		}
		int p = 1;
		for (int j = i; j < n; j++)
		{
			ss[i] += s[j];
		}
	}

	if (id == -1)
	{
		for (int i = 1; i <= n; i++) cout << "1"; 
		return;
	}

	for (int i = 0; i < id; i++) cout << "1";

	vector<string> ldk;
	for (int i = 0; i < id; i++)
	{
		string w = "";
		for (int j = id; j < n; j++) if (ss[i][j - id] == '1' || s[j] == '1') w += "1"; else w += "0";
		ldk.pb(w);
	}
	sort(ALL(ldk)); cout << ldk.back();	
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
   // cin >> testcase;
    while(testcase--)
        solve();
}
