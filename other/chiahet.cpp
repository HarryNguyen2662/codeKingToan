#include<bits/stdc++.h>
using namespace std;
int kt[1000006];
vector<long long> kk;
long long n,k;
void khoitao()
{
  kt[1] = 1;
  for (int i = 2; i*i<= 1e6+5; i++ )
    if (kt[i]==0)
    {
     kk.push_back(i);
    for (int j = i*i; j <= 1e6+5; j++)
    {
      kt[j] =1;
    }
   }
}
void solve()
{
  long long ans,ans1=1e18,dem,l,r;
  l = k;
  for (auto e:kk)
  {
    if (l % e ==0)
    {
      dem =0;
      while (l%e==0)
      {
        dem ++; 
        l = l/e;
      }
      r = e;
     ans = 0;
      while (n/r > 0)
      {
        ans +=(n/r);
        r = r*e;
      }
      if (dem>ans)
      {
        cout << -1; return;
      }
      ans1= min(ans,ans1);
    }
  }
  if (l>1)
  {
    r = l;
    ans =0;
      while (n/r > 0)
      {
        ans +=(n/r);
        r = r*l;
      }
      if (1>ans)
      {
        cout << -1; return;
      }
      ans1= min(ans,ans1);
  }
  cout << ans1 << endl;
}
int main()
{
    freopen("lololoin.txt","r",stdin);
    khoitao();
    int t;
    cin >> t;
    while(t--)
    {
      cin >> n >> k;
      solve();
    }
}