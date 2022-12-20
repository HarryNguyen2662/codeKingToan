#include<bits/stdc++.h>
using namespace std;
int dp[5000005];
int main()
{
    freopen("PALIN.INP", "r", stdin);
    freopen("PALIN.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);    
    int n; string s;
    cin >> n ;
    cin >> s;
     n = n*2-1;
    string a ;
    for (int i=0; i<n; i++) a+='#';
    for (int i = 0; i < n; i += 2) a[i] =s[i/2];
       // cout << a<<endl;
    int l = 0, r = -1, center, res = 0;
    for (int i = 0, j = 0; i < n; i++) {
        j = (i > r ? 0 : min(dp[l + r - i], r - i)) + 1;
        while (i - j >= 0 && i + j < n && a[i - j] == a[i + j]) j++;
        dp[i] = --j;
        if (i + j > r) {
            r = i + j;
            l = i - j;
        }
        int len=(dp[i]+i%2)/2*2+1-i%2;
        if (len > res) {
            res = len;
            center = i;
        }
    }
    cout << res;
}