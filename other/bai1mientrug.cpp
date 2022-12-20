#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
int xx[4] = {0,0,-1,1};
int yy[4]= {-1,1,0,0};
bool check(long long x)
{
    int tt = sqrt(x);
    for (int i  = 2; i <=tt ; i++)
        if (x%i == 0) return false;
    return true;
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("yeunhi.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    long long a,b;
    cin >> q;
    while (q--)
    {
        cin >> a;
        if (a == 1) cout << 0 << endl;
        else {

            b = a*a + (a-1)*(a-1) + a*(a-1);
            if (check(b)) cout << 1 << endl; else cout << 0 << endl;
        }
    }
}