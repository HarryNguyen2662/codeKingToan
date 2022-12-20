#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
int docao[200007];
long long fen[200007],giatri[200007];
void update(int p, long long val){
    for(int i = p; i <= 200005; i += i & -i)
        fen[i] = max(val,fen[i]);
}
long long mx(int p) {
    long long ans = 0;
    for(int i = p; i; i -= i & -i)
        ans =max(ans,fen[i]);
    return ans;
}
int main()
{
    freopen("yeunhi.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    long long as,ans=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> docao[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> giatri[i];
    }
    for (int i = 1; i <= n; i++)
    {
        as = mx(docao[i]-1); 
        ans = max(ans,as+giatri[i]);
        update(docao[i],giatri[i]+as);
    }
    cout << ans;
}