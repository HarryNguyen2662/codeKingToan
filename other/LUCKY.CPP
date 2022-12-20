#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("LUCKY.INP","r",stdin);
     freopen("LUCKY.OUT","w",stdout);
   // ios_base::sync_with_stdio(0);
   // cin.tie(0); cout.tie(0);
    long long n,t,sum; int dem;
    cin>>n;
    t=1;
    dem=0;
    while(sum<n)
    {
        dem++;
        t*=2;
        sum+=t;
    }
    sum-=t; n=n-sum;
    for(int i = 1 ;i<= dem; i++)
    {
        t/=2;
        if (n>t) 
            {
                cout<<"7";
                n-=t;
            }
            else cout<<"4";
    }
}