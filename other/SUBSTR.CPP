#include<bits/stdc++.h>
using namespace std;
int dp[2005][2005];
int main()
{
   // freopen("yeunhi.txt","r",stdin);
    freopen("SUBSTR.INP","r",stdin);
    freopen("SUBSTR.OUT","w",stdout);
    string s,st;
    int dem,ans=0;
    getline(cin,s);
 //  cout<<s<<endl;
    for (int i =0; i< s.size(); i++)
    {
        dem=0;
        for (int j = i -1; j>=0; j--)
        {
            if (2*i-j>=s.size()) break;
            if (s[j]==s[2*i-j]) dem++; else break;
        }
        ans=max(ans,2*dem+1);
        dem=0;
         for (int j = i ; j>=0; j--)
         {
             if (2*i-j+1>=s.size()) break;
            //if (i==3) cout<<j<<endl;
             if (s[j]==s[2*i-j+1]) dem++ ; else break;
         }
         //if (dem) cout<<i <<endl;
         //cout<<dem<<endl;
         ans=max(ans,2*dem);
    }
    cout<<ans<<endl;
    st="";
    for (int i =s.size()-1; i>=0; i--)
    {
        st+=s[i];
    }
    for (int i =1 ; i<= s.size(); i++)
        for (int j = 1; j<= st.size(); j++)
            if (s[i-1]==st[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j] =max(dp[i][j-1],dp[i-1][j]);
    cout<<dp[s.size()][st.size()];
}