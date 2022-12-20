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

int nhay[1000006][log+1], pre[1000006], suf[1000006], luu[1000006], sum[1000006], mx[1000006], high[1000006];

void solve() 
{
    int n;
    cin >> n;
    int id = 1, cnt = 1;
    mx[1] = -oo - 5;
    suf[0] = 1;
    pre[1] = 0;
    suf[1] = n + 5; 
    pre[n + 5] = 1;
    int lim = n + 5;
    while(n--)
    {
        char type;
        cin >> type;
        if (type == 'I')
        {
            int x;
            cin >> x;
            cnt++;
            pre[cnt] = id;
            pre[suf[id]] = cnt;
            suf[cnt] = suf[id];
            suf[id] = cnt;
            
            luu[cnt] = x;
            sum[cnt] = sum[pre[cnt]] + luu[cnt];
            mx[cnt] = max(sum[cnt], mx[pre[cnt]]);
            nhay[cnt][0] = id;
            high[cnt] = high[id] + 1;
            for (int j = 1; j <= log; j++) 
            {
                nhay[cnt][j] = nhay[nhay[cnt][j-1]][j-1];
            }
            id = cnt;
        }
        else if (type == 'D')
        {
            if (id != 1)
            {
                pre[suf[id]] = pre[id];
                suf[pre[id]] = suf[id];
                id = pre[id];
            }
        }
        else if (type == 'L')
        {
            if (pre[id] != 0) id = pre[id];
        }
        else if (type == 'R')
        {
            if (suf[id] != lim)
            {
                id = suf[id];
                sum[id] = sum[pre[id]] + luu[id];
                mx[id] = max(sum[id], mx[pre[id]]);
                nhay[id][0] = pre[id];
                high[id] = high[pre[id]] + 1;
                for (int j = 1; j <= log; j++) 
                {
                    nhay[id][j] = nhay[nhay[id][j-1]][j-1];
                }
                
            }
        }
        else
        {
            int x;
            cin >> x;
            int vt = id;
            for (int j = log; j >= 0; j--)
            if (high[nhay[vt][j]] >= x)
            {
                vt = nhay[vt][j];
            }
            //cout << high[vt] << endl;
            cout << mx[vt] << "\n";
        }
    }
}

int main() 
{   
   
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
    int testcase = 1;
    //cin >> testcase;
    while(testcase--)
        solve();
}
