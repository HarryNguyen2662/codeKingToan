#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 998244353;
const int MAXN = 1e6;
const int oo = 1e9;
int u[MAXN+5],sl[MAXN+5];
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    t= 1;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <=n; i++) u[i] = i;
        int kk = sqrt(n);
        sl[1] = 1;
        for (int i = 2; i<= kk; i++)
            if(sl[i] == 0)
                for (int j = i; j <=n; j+=i)
                {
                    int dem = 0;
                    while(u[j]%i==0)
                    {
                        dem++;
                        u[j]/=i;
                    }
                    if (sl[j]==0) sl[j] = (dem+1); else sl[j]=sl[j]*(dem+1);
                }
        for (int i = 2; i<= n; i++) if (u[i]!=1) {if (sl[i] == 0) sl[i]=2; else sl[i]=sl[i]*2;}
        long long res = 0,sum =0;
        for (int i = 1; i <= n; i++)
        {
            res = sum + sl[i]; 
            res%=MOD;
            sum = sum +res;
            sum%=MOD;
        }
        cout <<res<<endl;
    }
}