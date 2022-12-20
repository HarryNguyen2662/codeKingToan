#include <bits/stdc++.h>
using namespace std;
int kt[100005];
int dem[1000005];
vector<int> ldk;
int solve1(int l,int r)
{
    for (int i = l; i <= r ; i++)
            { 
                dem[i-l] = 0;
            }
       // cout << l <<" "<< r << endl;
        for (auto v :ldk)
        {
            //if (v==941) cout << "fefe";
            int u = (l/v+(l%v!=0))*v;  //cout << u << endl;
            //if (v==941) cout << 123;
            for (int i = u; i <= r; i+=v) dem[i-l] = 1; 
        }
        int ans =0;
        for (int i =l; i <= r; i++) if (dem[i-l]==0) ans++;
        return ans;
}
int main()
{
   // freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int u = sqrt(1e9);
    for (int i = 2; i*i <= u; i++)
        if (!kt[i])
            for (int j = i*i; j<= u; j+=i) kt[j]=1;
    for(int i = 2; i<= u; i++) if (!kt[i]) ldk.push_back(i);
    //cout << ldk.size();
     //  for (auto v : ldk) cout << v <<" ";
    int t,l,r;
    cin >> t;
    while(t--)
    {
        cin >> l >> r; 
        int ans=0,ans1=0;
        if (r<= ldk.back())
        {
            for (int i =0; i< ldk.size(); i++)
            {
                if (r>=ldk[i]) ans = i +1;
            }
            for (int i =0; i< ldk.size(); i++)
                if (l-1>=ldk[i]) ans1 = i+1;
            cout << ans-ans1 <<endl;
        }
        else
        {
            if (l<= ldk.back())
            {
                for (int i =0; i< ldk.size(); i++)
                if (l-1>=ldk[i]) ans1 = i+1;
                cout << ldk.size()-ans1+ solve1(ldk.back()+1,r)<<endl; 
            }
            else cout << solve1(l,r)<<endl;
        }
    }
}