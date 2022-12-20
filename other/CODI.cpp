#include<bits/stdc++.h>
using namespace std;
int kt[100005],kk[100005];
const int maxn= 1e5;
int main()
{
    freopen("CODI.INP","r",stdin);
    freopen("CODI.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t,l,r,mid,rr,a,b,dem,k,i; vector<int> ldk;
    for(int i = 1; i<= maxn; i++) kt[i] = 1;
    for (int i = 2; i<= maxn; i++) kk[i] = i;
    for( int i = 2; i*i <= maxn; i++)
        if(kt[i] == 1)
            for (int j = i; j<= maxn; j+=i)
            {
                dem = 0;
                while(kk[j]%i == 0)
                {
                    dem++;
                    kk[j]/=i;
                }
                kt[j]*=(dem+1);
            }
    for (int i = 2 ; i<= maxn; i++) if (kk[i]!=1) kt[i]*=2;
    ldk.push_back(1); for (int i = 1; i<= maxn; i++) 
    {
        ldk.push_back(ldk.back()+kt[ldk.back()]);
        if(ldk.back()>maxn) break;
    }
    //for (auto v : ldk) cout << v <<" ";
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        l = 0; r = ldk.size()-1;
        while(l<=r)
        {
            mid = (l + r)/2;
            if (ldk[mid] <= b) l = mid + 1; else r = mid - 1;
        }
        l = 0; rr= ldk.size()-1;
        while(l<=rr)
        {
            mid = (l + rr)/2;
            if (ldk[mid] >= a) rr = mid - 1; else l = mid + 1;
        }
        cout << r - l + 1<< endl;
        //cout<<ldk[r] <<" "<<ldk[l]<<endl;
    }
}