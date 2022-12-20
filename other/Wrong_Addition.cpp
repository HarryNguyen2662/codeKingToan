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

inline long long ReadInt() 
{
    char c;
    bool negative = false;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') negative = true;
    long long x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (negative) return -x; else return x;
}

void WriteInt(long long x) 
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9)
        WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void solve() 
{
	string s, st;
	cin >> s >> st;
	string res = "";
	int  l = (int)s.size() - 1 , r = (int)st.size() - 1;
	//cout << s << " " << st << endl;
	//cout << char(st[r]  -  s[l] + '0') << endl;
	while(l >= 0)
	{
		if (r < 0)
		{
			cout << "-1\n";
			return;
		}
		if (st[r] >= s[l])
		{

			//cout << "hoel" << endl;
			res = char(st[r] - s[l] + '0' ) + res;
			r--;
		}
		else
		{
			//cout << "hoel" << endl;
			if (r == 0 || st[r-1] != '1')
			{
				cout << "-1\n";
				return;
			}
			res = char(st[r] + 10 - s[l] + '0') + res;
			r -= 2;
		}
		l--;
		//cout << res << endl;
	}
	while(r >= 0)
	{
		res =  st[r] + res;
		r--;
	}
	reverse(ALL(res)); while((int)res.size() != 1 && res.back() == '0') res.pop_back(); reverse(ALL(res));
	cout << res << "\n";

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
