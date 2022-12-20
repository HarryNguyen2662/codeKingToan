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
map<int,int> dem;
struct Trienode
{
    int sl[18];
    int pass;
    int child[2];
    Trienode()
    {
        for (int i = 0; i <= log; i++) sl[i] = 0;
        child[0] = child[1] = -1;
        pass = 0;
    } 
};
int numnode = 0;
Trienode trie[200005];
void insert(const int &x)
{
    int p = 0;
    trie[p].pass++;
    for (int j = 0; j <= log; j++) if (x&mask(j)) trie[p].sl[j]++;
    for (int i = log; i >= 0; i --)
    {
        int t = ((x & mask(i)) > 0) ? 1 : 0;
        if (trie[p].child[t] == -1) trie[p].child[t] = ++numnode;
        p = trie[p].child[t];
        for (int j = 0; j <= log; j++) if (x&mask(j)) trie[p].sl[j]++;
        trie[p].pass++;
    }
}
void remove(const int &x)
{
    int p = 0;
    trie[p].pass--;
    for (int j = 0; j <= log; j++) if (x&mask(j)) trie[p].sl[j]--;
    for (int i = log; i >= 0; i --)
    {
        int t = ((x & mask(i)) > 0) ? 1 : 0;
        p = trie[p].child[t];
        for (int j = 0; j <= log; j++) if (x&mask(j)) trie[p].sl[j]--;
        trie[p].pass--;
    }
}
int X = 0;
long long getsum(const int &k)
{
    if (k == 0) return 0;
    int stt = 0;
    long long sum = 0;
    int p = 0;
    for (int j = 0; j <= log; j++) if (X&mask(j))  sum += 1ll*(trie[p].pass-trie[p].sl[j])*mask(j);
    else sum += 1ll*trie[p].sl[j]*mask(j);
    //cout << sum << endl;
    for (int i = log; i >= 0; i--)
    {
         int t = ((X & mask(i)) > 0) ? 1 : 0;
         if (t == 0)
         {
            if (trie[p].child[0] != -1)
            {
                stt += trie[trie[p].child[0]].pass;
            }
            if (stt >= k)
            {
                if (trie[p].child[1] != -1)
                {
                    int pp = trie[p].child[1];
                    for (int j = 0; j <= log; j++) if (X&mask(j))
                    {
                        int w = trie[pp].pass - trie[pp].sl[j];
                        sum -= 1ll*w*mask(j);
                        
                    }
                    else 
                    {
                        int w = trie[pp].sl[j];
                        sum -= 1ll*w*mask(j);
                    }
                }
                p = trie[p].child[0];
                stt -= trie[p].pass;
                continue;
            }
            p = trie[p].child[1];
         }
         else
         {
            if (trie[p].child[1] != -1)
            {
                stt += trie[trie[p].child[1]].pass;
            }
            if (stt >= k)
            {
                if (trie[p].child[0] != -1)
                {
                    int pp = trie[p].child[0];
                    for (int j = 0; j <= log; j++) if (X&mask(j))
                    {
                        int w = trie[pp].pass - trie[pp].sl[j];
                        sum -= 1ll*w*mask(j);
                        
                    }
                    else 
                    {
                        int w = trie[pp].sl[j];
                        sum -= 1ll*w*mask(j);
                    }
                }
                p = trie[p].child[1];
                stt -= trie[p].pass;
                continue;
            }
            p = trie[p].child[0];
         }
    }
    stt = k -stt;
    for (int j = 0; j <= log; j++) if (X&mask(j))
    {
        int w = max(trie[p].pass - trie[p].sl[j] - stt, 0);
        sum -= 1ll*w*mask(j);
        
    }
    else 
    {
        int w = max(trie[p].sl[j]-stt, 0);
        sum -= 1ll*w*mask(j);
    }
    return sum;
}

void solve() 
{
    int query;
    cin >> query;
    while (query--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int x;
            cin >> x; x ^= X;
            dem[x]++;
            insert(x);
        }
        else if (type == 1)
        {
            int x;
            cin >> x; x ^= X;
            if (dem[x] == 0) continue;
            dem[x]--;
            remove(x);
        }
        else if (type == 2)
        {
            int x;
            cin >> x; X ^= x;
        }
        else
        {
            int k; cin >> k;
            cout << getsum(k) <<"\n";
        }
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
    //cin >> testcase;
    while(testcase--)
        solve();
}
