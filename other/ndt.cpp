#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
map<pair<int,int>,int> dem;
pair<int,int> c[1050];
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
    long long dem1= 0,dem2=0,res =0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> c[i].f >> c[i].s;
    for(int i = 1; i <= n; i ++ )
        for (int j = i+1; j <= n; j++)
    {
        int x = c[i].f -c[j].f, y = c[i].s - c[j].s;
         if (x==0&&y==0) continue;
        int xy = __gcd(x,y); if (xy<0) xy=-xy;
        x/=xy; y/=xy;
        if (x==0) dem1++;
        else if (y==0) dem2++;
        else
        {
           // cout << x <<" "<<y<<endl;
            res =res + dem[{-y,x}];
            dem[{x,y}]++; dem[{-x,-y}]++;
        }
    }
    cout << res +dem1*dem2;
}