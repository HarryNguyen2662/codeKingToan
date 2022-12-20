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


void solve() 
{
	cout << "alo";
	int n;
	cin >> n;
	cout << n << endl;
	string s;
	cin >> s;
	cout << s[0] << endl;
	string st = "";
	for (int i = 0; i < n; i++) if (s[i] == '1') st += "0"; else st += "1";
	reverse(ALL(st)); while((int)st.size() > 1 && st.back() == 0) st.pop_back(); reverse(ALL(st));
	
	if ((int)st.size() == 1 && st == "0")
	{
		for (int i = 1; i < n; i++) cout << "1"; cout << "0";
		return;
	}

	st += s;

	int nn = (int)st.size(); int re = 0;
	vector<int> z(nn);
    for (int i = 1, l = 0, r = 0; i < nn; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
          	if (i >= nn - n)
          	{
          		re = max(re, z[i]);
          	}
          }

     for (int i = 0; i < n - nn; i++) cout << s[i] << " ";
     for (int i = n - nn; i < n; i++)
     {
     	if (re)
     	{
     		cout << "1"; re--;
     	}
     	else cout << s[i];
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
   // cin >> testcase;
    while(testcase--)
        solve();
}
