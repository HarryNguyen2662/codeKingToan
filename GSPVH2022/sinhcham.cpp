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

int a[2000];

void solve() 
{
	system("g++ std=c++11 A10_F.cpp -o A10_F.exe");
	system("g++ std=c++11 test.cpp -o test.exe");


	for (int i = 1; i <= 5; i++)
	{
		int n = 20; vector<int> ldk;
		for (int i = 1; i <= n; i++) ldk.pb(i);

		for (int i = 1; i < n; i++)
		{
			random_shuffle(ALL(ldk));
			a[i] = ldk.back(); ldk.pop_back();
		}
		int rr = ldk.back();

		vector<pair<int,int>> query;
		int cnt = 20;
		while(cnt != 1)
		{
			int r = rng()%(cnt - 1) + 2, l = rng()%(r - 1) + 1;
			query.pb({l, r}); cnt -= (r - l);
		}

		ofstream out("hellodking.txt");
		out << n << " " << (int)query.size() << " " << rr << "\n";

		for (int e = 1; e < n; e++) out << a[e] << " "; out << "\n";
		for (auto v : query) out << v.fi << " " << v.se << "\n";
		out.close();

		system("A10_F.exe"); system("test.exe"); 
		
		if (system("fc goodbyedking.txt goodbyedking1.txt") != 0)
		{
			cout << "sai roi nha"; return;
		}
		else
		{
			cout << "ACCEPTED\n";
		}
	}
	cout << "dung roi hehe";

}

int main() 
{   
    // #ifndef ONLINE_JUDGE
    // freopen("hellodking.txt","r",stdin);
    // freopen("goodbyedking.txt","w",stdout);
    // #else
    // //hellooooooo
    // #endif
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
