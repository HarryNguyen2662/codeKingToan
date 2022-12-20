#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
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
    long long a,b,x,y;
    cin >> a >> b;
    cin >> x >> y;
    long long t = __gcd(a,x), tt = __gcd(b,y);
    if(a/t==b/tt&&x/t==y/tt)
    {
    	cout << "YES";
    	return 0;
    }
    t = __gcd(a,y); tt = __gcd(b,x);
    if (a/t==b/tt&&y/t==x/tt)
    {
    	cout<<"YES";
    	return 0;
    }
    cout << "NO";
}