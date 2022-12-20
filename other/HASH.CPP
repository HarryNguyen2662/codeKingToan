#include <bits/stdc++.h>
using namespace std;
 
long long pw(long long a, long long n, long long MOD) {
    if (n == 0) return 1;
    long long q = pw(a, n / 2, MOD);
    if (n % 2 == 0) return q * q % MOD;
    return q * q % MOD * a % MOD;
}
struct HS {
    string s;
    long long BASE, MOD;
    vector<long long> inv, ps;
    HS(string s, long long BASE = 922005, long long MOD = 1e9 + 2277):
                                            BASE(BASE), MOD(MOD) {
        long long invB = pw(BASE, MOD - 2, MOD);
        int n = s.size();
        
        inv.resize(n + 1);
        ps.resize(n + 1);
 
        inv[0] = 1;
        long long curPw = 1;
        for (int i = 1; i <= n; i++) {
            inv[i] = inv[i - 1] * invB % MOD;
            ps[i] = (ps[i - 1] + s[i - 1] * curPw) % MOD;
 
            curPw = curPw * BASE % MOD;
        }
    }
 
    int qy(int l, int r) {
        l++; r++;
        return (ps[r] - ps[l - 1] + MOD) * inv[l] % MOD;
    }   
}; 
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define NMOD 2
const double PI = 3.14159265389793238462643383279502884197169;
const long long HSMOD[4] ={(long long)1e9 + 2277, (long long)1e9 + 5277, (long long)1e9 + 8277, (long long)1e9 + 9277};
const long long MOD = 1e9 + 7;
const int MAXN = 500000;
const int oo = 1e9;
const long long BASE = 256;
long long pw[NMOD][500001];
bool minimize(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    else return false;
}

int main()
{
     #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission    
    #endif
    string s; int l,r,mid,n,i;
    cin>>s;
    n=s.length(); HS st(s);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] <<" "<<st.qy(i,i)<<endl;
    }
 }