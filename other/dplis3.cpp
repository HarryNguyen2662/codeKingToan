#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
pair<int,int> dp[200005],fen[200005],a[200005];
int ct[200005],tv[200005];
void update(int p, int val, int j){
    for(int i = p; i <= 100005; i += i & -i)
        if (fen[i].f < val) fen[i] = {val,j};
        else if (fen[i].f==val&&ct[fen[i].s]>ct[j]) fen[i] = {val,j};
}
pair<int,int> mx(int p) {
    pair<int,int> ans = {0,0};
    for(int i = p; i; i -= i & -i)
     if (fen[i].f > ans.f) ans = fen[i];
        else if (fen[i].f==ans.f&&ct[fen[i].s]<ct[ans.s]) ans.s = fen[i].s;
    return ans;
}
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    pair<int,int> as,ans = {0,0};
    cin  >> n;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i].f;
        a[i].s= i;
        tv[i] = a[i].f;
        //m = min (m,a[i]);
    }
    sort(a+1,a+n+1);
    ct[a[1].s] = 1;
    for (int i = 2; i<= n; i++)
        if (a[i].f!=a[i-1].f) ct[a[i].s] = ct[a[i-1].s]+1; else ct[a[i].s]=ct[a[i-1].s];
    for (int i = 1; i<= n; i++)
    {

        as = mx(ct[i]-1); dp[i]= {as.f+1,as.s};
       // cout <<ct[i]<<" "<< dp[i].f<<" "<<dp[i].s<<endl;
         update(ct[i],dp[i].f,i);
        if (dp[i].f > ans.f) ans = {dp[i].f,i};
        else if (dp[i].f==ans.f&&ct[i]<ct[ans.s]) ans.s = i;
    }
    cout <<ans.f<<endl;
    int t = ans.s;
   // cout << t <<endl;
   // dp[0].s=-1;
    vector<int> ldk;
    while(t)
    {
        ldk.push_back(t);
        t=dp[t].s;
    }
    for(int i = ldk.size()-1; i>=0; i--) cout << tv[ldk[i]]<<" ";
}