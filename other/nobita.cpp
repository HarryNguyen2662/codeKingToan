#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define log 18
#define mask(i) (1 << (i))
const double PI = 3.14159265389793238462643383279502884197169;
const long long MOD = 1e9 + 7;
const int MAXN = 1e6+5;
const int oo = 1e9;
int st[400005];
int a[400005];
void build(int id, int l, int r)
{
  if (l > r) return;
  if (l == r){
   st[id] = a[l];

   return;
 }
  int mid = (l + r)/2;
  build(id*2, l , mid);
  build(id*2 + 1, mid + 1, r);
  st[id] = min(st[id*2], st[id*2 + 1]);
}
void update(int id, int l, int r, int i, int val)
{
  if (i < l || i > r) return;
  if (l == r)
  {
    st[id] = val;
     //cout << i << " " << a[i]<<endl;
    return;
  }  
  int mid = (l + r)/2;
  update(id*2, l, mid, i, val);
  update(id*2 + 1, mid + 1, r, i ,val);
  st[id] = min(st[id*2], st[id*2 + 1]);
}
int getres(int id, int l, int r, int u, int v, int k)
{
  if (st[id] > k) return -1;
  if (r < u || l > v) return -1 ;
  if (l == r) return l;
  int mid = (l + r)/2;
  int ge = -1;
  if (st[id] <= k) ge= getres(id*2, l, mid, u, v,k);
  if (ge !=-1) return ge;
  return getres(id*2 + 1, mid+1, r,u, v, k);
}
int main()
{
     #ifndef ONLINE_JUDGE
       freopen("hellodking.txt","r",stdin);
    #else
    // online submission
    #endif
    // freopen("pupil.inp","r",stdin);
    // freopen("pupil.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, u, v, val, type;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    cin >> a[i];
    build(1,1,n);
    while (q--)
    {
      cin >> type;
      if (type == 1)
      {
        cin >>u >> v;
        update(1,1,n,u,v);
      }
      else
      {
        cin >> u >> v >> val;
        int res = getres(1,1,n,u,v,val);
        if (res > 0) cout << res <<"\n"; else cout << "Skip"<<"\n";
      }
    }
} 