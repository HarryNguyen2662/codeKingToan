 #include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
const long long MOD = 1e9 + 7;
int kt[1000005];
int ssl[1000005];
long long MAX = 1e13;
long long power(long long a, int b)
{
    if (b==0) return 1;
    long long y = power(a,b/2);
    if (y < MAX/y) y = y*y; else 
       y= MAX;
    //y= y*y;
    if (b%2==1)
    {
       if (y < MAX/a) y = y*a; else 
      y= MAX;
    //    y=y*a;
     //y = y*a;
    } 
    return y;
}
long long can(int v, long long m)
{
  //  if (v==1 && m > 1000000) return 0;
    long long l = 1, r =min(m,1ll*1000000);
    //cout <<r << endl;
    while(l <= r)
    {
        long long mid = (l+r)/2;
        if (power(mid,v) <= m) l = mid + 1; else
      //  cout <<mid<<" "<<v<<endl;
         r = mid -1;
    }
    return ssl[r];
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("cprime.inp","r",stdin);
        freopen("cprime.out","w",stdout);
    #else
    // online submission
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; vector<int > ldk;
    for (int i = 2; i*i <= 1e6; i++)
        if (!kt[i])
            for (int j = i*i; j<= 1e6; j+=i)
                kt[j] = 1;
    ssl[2] = 1;
    for (int i = 3; i <= 1e6; i++) ssl[i] = ssl[i-1] + (kt[i] == 0);
    for(int i = 2; i <=40 ; i++) if(!kt[i]) ldk.push_back(i-1);
    //cout << ldk.size()<<endl;
    cin >> t; long long a,b;
    while(t--)
    {
        cin >> a >> b;
        a--;
        long long sl1=0,sl2= 0;
        for (auto v : ldk)  
        {
            sl1+= can(v,a);
            sl2 +=  can(v,b);
        } 
        cout <<sl2-sl1<<endl;
    }
 //   cout << power(1000,100);
}