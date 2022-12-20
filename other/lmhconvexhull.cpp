#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
vertex a[100005];
int n;
halfStack hs;
long long ccw(vertex w, vertex u, vertex v) {
    u -= w;
    v -= w;
    return (long long)u.X * v.Y - (long long)u.Y * v.X;
}
bool cmp(vertex u, vertex v) { return ccw(a[1], u, v) > 0; }
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
main() 
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);  
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
    long long r = 0;
    int dai = (int)hs.size() - 1;
    cout << dai <<"\n";
     int id = 0;
    for (int i = 0; i < dai; i++)
    {
        if (a[hs[i]].Y < a[hs[id]].Y) id = i;
        else if (a[hs[i]].Y == a[hs[id]].Y && a[hs[i]].X == a[hs[id]].X) id = i;
        r += 1ll * (a[hs[i]].X - a[hs[i + 1]].X) * (a[hs[i]].Y + a[hs[i + 1]].Y);
    }
    cout << r/2 << ".";
    if (r%2) cout <<"5\n"; else cout << "0\n";
    for (int i = id; i < dai; i++) cout << a[hs[i]].X << " " << a[hs[i]].Y <<"\n";
    for (int i = 0; i < id; i ++) cout << a[hs[i]].X << " " << a[hs[i]].Y <<"\n";
    
}
