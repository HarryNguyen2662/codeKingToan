#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e6 + 3;
const int MAXN = 1e6;
const int oo = 1e9;
vector<string> ans,ldk;
map<string, int> dem;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++)
    {
        getline(cin, s);
        ldk.pb(s);
    }
    cout << ldk.size()<<endl;
    sort(ldk.begin(),ldk.end());
    for (int i =1 ;i < ldk.size(); i++)
        if (ldk[i]!=ldk[i-1])
        {
            int k = ldk[i-1].size()-1;
            string tt="";
            while (ldk[i-1][k]!=' ') 
            {
                tt+= ldk[i-1][k]; k--;
            }
            cout << ldk[i-1] << endl;
            reverse(tt.begin(),tt.end());
            if (dem[tt] == 0) ans.pb(tt);
            dem[tt]++;
        }
     int k = ldk.back().size()-1;
            string tt="";
            while (ldk.back()[k]!=' ') 
            {
                tt+= ldk.back()[k]; k--;
            }
            //cout << tt << endl;
            reverse(tt.begin(),tt.end());
            if (dem[tt] == 0) ans.pb(tt);
            dem[tt]++;
    //cout << ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for (auto v : ans) 
    {
        cout << v <<" "<<dem[v]<<" "; if (dem[v]>=10) cout << "YES" <<endl; else cout << "NO"<<endl;
    }
}
