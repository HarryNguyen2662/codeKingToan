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
const long long BASE = 11062004;
const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
long long pw[100005];
vector<long long> HashT[100005];
void solve() 
{
	string s;
	cin >> s;
	
    int n;
	cin >> n;
	
    vector<int> difflen; 

    for (int i = 1; i <= n; i++)
	{
        string t;
		cin >> t;
        int len = (int)t.size();
		HashT[len].pb(0);
		difflen.pb(len);
		for (int j = 0; j < (int)t.size(); j++) HashT[len].back() = (HashT[len].back()*BASE%HSMOD[0] + t[j] - 'a' + 1)%HSMOD[0];
	
    }  
   
    sort(ALL(difflen)); difflen.resize(unique(ALL(difflen)) - difflen.begin());
    for (auto v : difflen) sort(ALL(HashT[v]));
    vector<long long> HashS;
    vector<char> res;
   
    HashS.pb(0);
    pw[0] = 1;
    for (int i = 0 ; i < (int)s.size(); i++)
    {
        pw[i+1] = pw[i]*BASE%HSMOD[0];
        res.pb(s[i]); HashS.pb((HashS.back()*BASE%HSMOD[0] + s[i] - 'a' + 1)%HSMOD[0]);
        for (auto v : difflen) if ((int)HashS.size() >= v)
        {
            long long w = (HashS.back() - HashS[(int)HashS.size() - v - 1]*pw[v]%HSMOD[0] + HSMOD[0])%HSMOD[0];
            int id = lower_bound(ALL(HashT[v]), w) - HashT[v].begin();
            if (id != (int)HashT[v].size() && w == HashT[v][id])
            {
                for (int e = 1; e <= v; e++) HashS.pop_back(), res.pop_back();
            }
        }
        else break;
    }
    for (auto v : res) cout << v;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
