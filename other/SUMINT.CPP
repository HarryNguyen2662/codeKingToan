#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("SUMINT.INP", "r", stdin);
    freopen("SUMINT.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    long long n,z,a,b;
    vector<pair<long long, long long > > ldk;
    cin>> n; n = n*2;
    for (long long i =1 ;i*i <= n; i++)
    if (n%i==0)
    {
        z=n/i;
        a=(z+i-1);
        if (a%2!=0) continue;
        a=a/2;
        b=z-a;
        if (b>=a) continue;
        ldk.push_back({b,a});
    }
    cout << ldk.size()<<endl;
    for(int i =0; i < ldk.size(); i++) cout << ldk[i].first << " "<< ldk[i].second << endl;
}