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

struct Trie
{
    int child[2]; vector<int> pass;

    Trie()
    {
        child[0] = child[1] = 0;
    }
} node[5000005];

const int lim = 1000000;

int cs[100005], mx[100005][log + 3], mn[100005][log + 3], cost[100005], luu[1000005], cnt = 0, lg[100005];
string s[100005];

vector<int> lu[100005];

void buildtrie()
{
    int p = ++cnt;

    luu[0] = p;

    for (int i = 1; i < lim; i++)
    {
        node[p].child[0] = ++cnt;
        p = node[p].child[0]; luu[i] = p;
    }
}


void insert(int id)
{
    int p = luu[lim - (int)s[id].size()];

    for (int i = 0; i < (int)s[id].size(); i++)
    {
        int cur = s[id][i] - '0';
        if (node[p].child[cur] == 0) node[p].child[cur] = ++cnt;

        p = node[p].child[cur];
        node[p].pass.pb(id);
        lu[id].pb(p);
    }

}

bool cmp(const int &x, const int &y)
{
    if ((int)s[x].size() == (int)s[y].size())
    {
        for (int i =  0; i < (int)s[x].size(); i++)
        if (s[x][i] != s[y][i])
        {
            return s[x][i] < s[y][i];
        }
    }

    return (int)s[x].size() < (int)s[y].size();
}

int maxx(const int &x, const int &y)
{
    return (cost[x] < cost[y] ? y : x);
}

int getmx(const int &l, const int &r)
{
    int k = lg[r - l + 1];

    return maxx(mx[l][k], mx[r - mask(k) + 1][k]);
}

int getmn(int l, int r)
{
    int k = lg[r - l + 1];

    return min(mn[l][k], mn[r - mask(k) + 1][k]);
}


void solve() 
{
    int n, q;
    cin >> n >> q;


    buildtrie();

    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];

        reverse(ALL(s[i]));
        while((int)s[i].size() > 1 && s[i].back() == '0') s[i].pop_back();
        reverse(ALL(s[i]));
        
        insert(i);

        cs[i] = i;
    }

    sort(cs + 1, cs + 1 + n, cmp);

    for (int i = 1; i <= n; i++)
    {
        cost[cs[i]] = i;
        mx[i][0] = i;
        mn[i][0] = (int)s[i].size();
        while(mask(lg[i]) <= i) lg[i]++; lg[i]--;
    }

    for (int i = 1; i <= log; i++) for (int j = 1; j <= n - mask(i) + 1; j++)
    {
        mx[j][i] = maxx(mx[j][i - 1], mx[j + mask(i - 1)][i - 1]);
        mn[j][i] = min(mn[j][i - 1], mn[j + mask(i - 1)][i - 1]);
    }

    // cout << getmx(3, 4) << endl;
    // cout << getmin(1, 2) << endl;

    while(q--)
    {
        int l, r; string st;
        cin >> l >> r >> st;

        int max_id = getmx(l, r), min_len = getmn(l, r), p = -1;

        if ((int)s[max_id].size() <= (int)st.size()) p = luu[lim - (int)st.size()];
        else p = lu[max_id][(int)s[max_id].size() - (int)st.size() - 1];

        for (int i = 0; i < (int)st.size(); i++)
        {
            int cur =  (st[i] - '0');
            int nextp1 = node[p].child[1 - cur], nextp2 = node[p].child[cur];
           
            if (nextp1)
            {
                if (nextp1 <= lim)
                {
                    if (lim - nextp1 + 1 >= min_len)
                    {
                        p = nextp1;
                    }
                    else
                    {
                        p = nextp2;
                    }
                }
                else
                {
                    int kt = lower_bound(ALL(node[nextp1].pass), l) - node[nextp1].pass.begin();
                    
                    if (kt < (int)node[nextp1].pass.size() && node[nextp1].pass[kt] <= r)
                    {
                        p = nextp1;
                    } 
                    else
                    {
                        p = nextp2;
                    }
                }
            } 
            else
            {
                p = nextp2;
            }
        }

        int re = lower_bound(ALL(node[p].pass), l) - node[p].pass.begin();
        cout << node[p].pass[re] << "\n";
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
