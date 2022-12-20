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
long long a[500005], b[500005], aa[500005];
int n, rr;
long long k;
bool check(long long val)
{
    long long toadd = k;
    deque<int> st;
    long long cur = 0, add;
    for (int i = 1; i <= n; i++) aa[i] = a[i];
    for (int i = 1; i <= rr + 1; i++)
    {
        cur += aa[i];
        if (aa[i] < b[i]) st.pb(i);
    }
    if (cur < val)
    {
        add = val - cur;
        toadd -= add;
        if (toadd < 0) return false;
        while(!st.empty() && add > 0)
        {
            int j = st.back(); st.pop_back();
            cur -= aa[j];
            long long t = min(add, b[j] - aa[j]);
            add -= t; aa[j] += t;
            cur += aa[j];
            if (aa[j] < b[j]) st.pb(j);
        } 
        if (add > 0) 
        {
            //cout << rr << endl;
            return false;
        }
    }
    for (int i = rr + 2; i <= n; i++)
    {
        cur += aa[i]; 
        if (i > 2*rr + 1)
        cur -= aa[i-2*rr-1];
        if (aa[i] < b[i]) st.pb(i);
        if (!st.empty() && st.front() == i - 2*rr - 1) st.pop_front();
        if (cur < val)
        {
            add = val - cur;
            toadd -= add;
            if (toadd < 0) return false;
            while(!st.empty() && add > 0)
            {
                int j = st.back(); st.pop_back();
                cur -= aa[j];
                long long t = min(add, b[j] - aa[j]);
                add -= t; aa[j] += t;
                cur += aa[j];
                if (aa[j] < b[j]) st.pb(j);
            } 
            if (add > 0) 
            {
               // cout << i << endl;
                return false;
            }
        }
    }
    for (int i = max(n - 2*rr, 1); i < n - rr; i++)
    {
        cur -= aa[i];
        if (!st.empty() && st.front() == i) st.pop_front();
        if (cur < val)
        {
            add = val - cur;
            toadd -= add;
            if (toadd < 0) return false;
            while(!st.empty() && add > 0)
            {
                int j = st.back(); st.pop_back();
                cur -= aa[j];
                long long t = min(add, b[j] - aa[j]);
                add -= t; aa[j] += t;
                cur += aa[j];
                if (aa[j] < b[j]) st.pb(j);
            } 
            if (add > 0) 
            {
               // cout << i << endl;
                return false;
            }
        }
    }
    return true;
}
void solve() 
{
    
    cin >> n >> rr >> k;
    //rr = min(n, 2*rr + 1);
    long long l = 1, r = k + 1106;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r += a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
   // cout << check(38);
    while(l <= r)
    {
        long long mid = (l + r)/2;
        if (check(mid)) l = mid + 1; else r = mid - 1;
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
    //freopen("task.inp","r",stdin); freopen("task.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
