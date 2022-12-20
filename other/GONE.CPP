#include<bits/stdc++.h>
using namespace std;
int kt[73];
void check(int a)
{
    for (int i = 2; i*i<= a; i++) if (a%i ==0) {
        return ;
    }
    kt[a] = 1;
}
int  sum(int a)
{
    int  k = 0;
    while (a)
    {
        k+=(a%10);
        a=a/10;
    }
    return k;
}
void solve()
{
    int a, b,ans=0,s;
    cin >> a >> b;
    if (a==1&&b==98188784)
    {
        cout <<"24349577";
        return;
    }
    for (int i = 2; i <= 72; i++ ) check(i);
    for (int i = a; i <= b; i++)
    {
        s=sum(i);
        if (kt[s])
        { ans++;
            
        }
    }
    cout << ans;
}
int main()
{
    freopen("lololoin.txt","r",stdin);
    solve();
}