#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define int int64
int check[5004];
struct vertex {
    int X, Y;
    void operator-=(vertex v) {
        X -= v.X;
        Y -= v.Y;
    }
    bool operator>(vertex v) {
        if (v.Y == Y)
            return X > v.X;
        else
            return Y > v.Y;
    }
};
class halfStack : public vi {
   public:
    void clll() { clear(); }
    void pop() { pop_back(); }
    void push(int v) { push_back(v); }
    int below() { return at(size() - 2); }
    int top() { return at(size() - 1); }
};
vertex a[23997];
int n;
halfStack hs;
int64 ccw(vertex w, vertex u, vertex v) {
    u -= w;
    v -= w;
    return (int64)u.X * v.Y - (int64)u.Y * v.X;
}
bool cmp(vertex u, vertex v) { return ccw(a[1], u, v) > 0; }
int64 lllabs(int64 a) { return a > 0 ? a : -a; }

void graham() {
    int k = 1; hs.clll();
    while (k <= n + 1) {
        if (hs.size() < 2)
            hs.push(k++);
        else {
            if (ccw(a[hs.below()], a[hs.top()], a[k]) <= 0)
                hs.pop();
            else
                hs.push(k++);
        }
    }
}
long long cal(int w,int ww,int www)
{
    return abs((a[ww].X- a[w].X)*(a[www].Y- a[w].Y)-(a[ww].Y- a[w].Y)*(a[www].X- a[w].X));
}
main() {
 //   freopen("MILITARY.INP","r",stdin);
  //  freopen("MILITARY.OUT","w",stdout);
      freopen("yeunhi.txt","r",stdin);
    vector<vertex> ldk; long long ans=0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].X >> a[i].Y;
    while(n>2)
    {
      for (int i = 1; i <= n; i++)
            if (a[i] > a[1]) {
            vertex z = a[i];
            a[i] = a[1];
            a[1] = z;
             }   
        sort(a + 2, a + n + 1, cmp);
         a[n + 1] = a[1];
         graham();
         cout << hs.size()<<endl;
         memset(check,0,sizeof check);
        for(int i = 0; i< hs.size()-1; i++) check[hs[i]]=1;
        for (int i = 1; i<= n; i++) if (!check[i]) ldk.push_back(a[i]);
        n = n-hs.size()+1; for (int i = 1; i<= n; i++) a[i]=ldk[i-1]; ldk.clear();
        ans ++;
    }
    cout << ans;
}