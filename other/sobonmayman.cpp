#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
int n[10000005],sl[10000005],uoc[10000005];
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
    for (int i = 1; i<= 1e7; i++) n[i] = i;
    for (int i = 2; i<=3162; i++)
        if (uoc[i] == 0)
        for (int j = i; j <= 1e7; j+=i)
        {
            int dem = 0;
            while (n[j]%i==0)
            {
                dem++;
                n[j]/=i;
            }
            if (uoc[j] == 0) uoc[j] = dem+1; else uoc[j] = uoc[j]*(dem+1);
        }
    for (int i = 2; i<= 1e7; i++)
    {
        if (n[i]!=1) {if (uoc[i] == 0 ) uoc[i] = 2; else uoc[i]=uoc[i]*2;}
        sl[i] = sl[i-1] + (uoc[i] == 4);
    }
    int t,l,r;
    cin >> t;
    while (t--)
    {
        cin >> l >> r;
        cout << sl[r] - sl[l-1]<<endl;
    }
}