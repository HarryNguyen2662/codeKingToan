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

vector<string> ldk, dk;
int kt = 0, stt = 0;;
pair<int, string> a[100];
bool dd[10];

void back_track(int id)
{
	if (id == 6)
	{
		stt++;
		//for (auto v : ldk) cout <<v <<" ";
			//cout << endl;
		if (stt == a[6].fi)
		{
			kt = true;
		}
		return;
	}
	for (int i = 1; i <= 5; i++) if (dd[i] == false)
	{
		ldk.pb(a[i].se); dd[i] = true;
		back_track(id + 1);
		if (kt) return;
		ldk.pop_back(); dd[i] = false;
	}
}

void guess(int id)
{
	if (id == 6)
	{
		stt++;
		kt = stt;
		for (int i = 0; i < 5; i++) if (ldk[i] != dk[i])
		{
			kt = 0; break;
		} 
		return;
	}
	for (int i = 1; i <= 5; i++) if (dd[i] == false)
	{
		ldk.pb(a[i].se); dd[i] = true;
		guess(id + 1);
		if (kt) return;
		ldk.pop_back(); dd[i] = false;
	}
}

void solve() 
{
	string type;
	cin >> type;
	if (type == "AN")
	{
		for (int i = 1; i <= 6; i++)
		{
			string s;
			cin >> s;
			if ((int)s.size() == 2)
			{
				if (s[0] >= '0' && s[0] <= '9') a[i].fi = s[0] - '0' - 1;
				else if (s[0] == 'J') a[i].fi = 10;
				else if (s[0] == 'Q') a[i].fi = 11;
				else if (s[0] == 'K') a[i].fi = 12;
				else a[i].fi = 13;
			} else a[i].fi = 9;
			if (s.back() == 'C') a[i].fi += 13;
			if (s.back() == 'T') a[i].fi += 26;
			if (s.back() == 'H') a[i].fi += 39;
			a[i].se = s;
			dd[i] = false;
		}
		sort(a + 1, a + 7);
		kt = 0; stt = 0; ldk.clear();
		back_track(1);
		
		for (auto v : ldk) cout << v << " ";
		cout << endl;
	}
	else
	{
		dk.clear();
		for (int i = 1; i <= 5; i++)
		{
			string s;
			cin >> s;
			if ((int)s.size() == 2)
			{
				if (s[0] >= '0' && s[0] <= '9') a[i].fi = s[0] - '0' - 1;
				else if (s[0] == 'J') a[i].fi = 10;
				else if (s[0] == 'Q') a[i].fi = 11;
				else if (s[0] == 'K') a[i].fi = 12;
				else a[i].fi = 13;
			} else a[i].fi = 9;
			if (s.back() == 'C') a[i].fi += 13;
			if (s.back() == 'T') a[i].fi += 26;
			if (s.back() == 'H') a[i].fi += 39;
			a[i].se = s;
			dk.pb(s);
			dd[i] = false;
		}
		sort(a + 1, a + 6);
		kt = 0; stt = 0;
		ldk.clear();
		guess(1);
		
		int x = kt%13, y = (kt - 1)/13 + 1;
		if (x == 0) x = 13; x++;

		if (x <= 10) cout << x; else if (x == 11) cout << "J"; else if (x == 12) cout << "Q";
		else if (x == 13) cout << "K"; else cout << "A";
		if (y == 1) cout << "P"; else if (y == 2) cout << "C"; else if (y == 3) cout << "T";
		else cout << "H";		
		
		cout << endl;	
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
    cin >> testcase;
    while(testcase--)
        solve();
}
