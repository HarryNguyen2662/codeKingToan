#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define int int64
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
    int k = 1;
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
freopen("TRILAND.INP","r",stdin);
    freopen("TRILAND.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].X >> a[i].Y;

    for (int i = 1; i <= n; i++)
        if (a[i] > a[1]) {
            vertex z = a[i];
            a[i] = a[1];
            a[1] = z;
        }   
    sort(a + 2, a + n + 1, cmp);
    a[n + 1] = a[1];
    graham();
    //cout << hs.size();
//cout << ans/2<<"."<<(ans%2?5:0);
   int x = 0, y=1, z=2;
   int xa=x, yb=y, zc=z;
   int ss=hs.size()-1;
//   for (int i = 0; i< ss; i++) cout << hs[i]<<" ";
  //  cout << endl;
   while(true)
{
    while(true)
    {
        while(cal(hs[x],hs[y],hs[z])<= cal(hs[x],hs[y],hs[(z+1)%ss]))
            z=(z+1)%ss;
        if(cal(hs[x],hs[y],hs[z])<= cal(hs[x],hs[(y+1)%ss],hs[z]))
        {
            y=(y+1)%ss;
            continue;
        }
        else break;
    }
    if(cal(hs[x],hs[y],hs[z])>= cal(hs[xa],hs[yb],hs[zc]))
    {
        xa=x; yb=y; zc=z;
    }
    x=(x+1)%ss;
    if(x==y) y=(y+1)%ss;
    if(y==z) z=(z+1)%ss;
    if (x==0) break;
}
long long ans = cal(hs[xa],hs[yb],hs[zc]),ans1=0;
//cout << hs[xa]<<" "<<hs[yb]<<" "<<hs[zc]<<endl;
cout << ans/2 <<"."<<(ans%2?5:0)<<endl;
  // for (int i = 0; i< ss; i++)
  //       for(int j = i+1; j< ss; j++)
  //           for (int e = j+1; e< ss; e++)
  //               ans1= max(ans1,cal(hs[i],hs[j],hs[e]));
  //   cout << ans1/2 <<"."<<(ans1%2? 5: 0);
}