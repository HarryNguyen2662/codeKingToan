#include<bits/stdc++.h>
using namespace std;
int docao[1005],a[1005][1005],d[10],x[1005],y[1005];
int main()
{
//    freopen("yeunhi.txt","r",stdin);
    int n,ans=0; stack<int> s,ss;
    cin >> n;
    for (int i=1; i<= n; i++)
        for (int j=1; j<=n; j++) 
            cin>>a[i][j];
    for (int e=0; e<=9; e++)
    {
        if(e) d[e-1]=0; d[e]=1;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<= n; j++)
            {
                docao[j] = (d[a[i][j]])? docao[j]+1:0;
                while(!s.empty()&&docao[s.top()]>=docao[j]) s.pop();
                x[j]=(!s.empty())? s.top()+1:1;
                s.push(j);
            }
            for(int j =n ; j; j--)
            {
                while(!ss.empty()&&docao[ss.top()]>=docao[j])ss.pop();
                y[j]=(!ss.empty())? ss.top()-1:n;
                ss.push(j);
            }
            while(!ss.empty())ss.pop();
            while(!s.empty())s.pop();
            for (int j = 1; j<=n; j++)
            {
                int rong=y[j]-x[j]+1;
                if (rong>=docao[j]) 
                    {
                        ans= max(ans,docao[j]*docao[j]);
                       // if (docao[j]*docao[j]==16) cout<<docao[x[j]]<<" "<<docao[y[j]]<<endl;
                    }
            }
        }
        memset(x,0,sizeof x); memset(y,0,sizeof y); memset(docao,0,sizeof docao);
    }
    cout<<ans;
}