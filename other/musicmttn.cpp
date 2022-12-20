#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6;
const int oo = 1e9;
pair<long long ,long long > cost[1000050], costt[1000050];
int t[1000050];
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
    int n, d, p;
    vector<pair<int,int> > ldk,dk;
    vector<int >tnt;
    cin >> n;
     for (int i= 1; i <= n; i++)
    {
    	cin >> p >> t[i] >> d;
    	ldk.pb({p+d,i}); dk.pb({p-d,i});
    	tnt.pb(p+d); tnt.pb(max(0,p-d));
    }
    sort(ldk.begin(),ldk.end());
    sort(dk.begin(),dk.end());
    sort(tnt.begin(),tnt.end());
     for (int i = 1; i <= n;  i++)
    {
         cost[i].f = cost[i-1].f + 1ll*ldk[i-1].f*t[ldk[i-1].s];
         cost[i].s = cost[i-1].s+t[ldk[i-1].s];
    }
    for (int i = n; i >=1 ;  i--)
    {
         costt[i].f = costt[i+1].f + 1ll*dk[i-1].f*t[dk[i-1].s];
         costt[i].s = costt[i+1].s+t[dk[i-1].s];
    }
    int l =0, r = 1;
    long long res= 1e18;
    for(auto v: tnt)
    {
    	while (l + 1 <= n && ldk[l].f < v) l++;
    	while (r < n && dk[r-1].f <= v) r++;
    	//cout << v<<" "<<l<<" "<<r<<endl;
    	long long re = 0;
    	if (ldk[l-1].f < v) re = 1ll*cost[l].s*v - cost[l].f;
    	if (dk[r-1].f > v) re+= (costt[r].f -1ll*costt[r].s*v);
    	res = min(res,re); 
    	//cout << re<<endl;
    }
    cout << res;
}