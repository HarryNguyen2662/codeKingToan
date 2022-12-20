#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
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
    int t;
    string s,st;
    cin >> t;
    while (t--)
    {
        cin >> s;
        st =s;
        int n = s.size();
        reverse(st.begin(), st.end());
        int l=0,r=0,ll=0,rr=-1;
        while (l<n)
        {
            r = l-1;
            while (r +1< n&& s[r+1]==st[r+1]) r++;
            if (rr-ll < r-l)
            {
                rr=r;
                ll=l;
            }
           if (r>=l) l = r + 1; else l++;
        }
        for (int i = ll; i <= rr; i++) cout <<s[i];
        cout <<endl;
    }
}