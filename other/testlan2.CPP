#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define setp setprecision
#define mask(i) (1ll << (i))
#define getbit1(x) __builtin_popcount(x)
#define hoanvi next_permutation
int x, y, d;
void euclid(int a, int b)
{
    if (b == 0)
    {
        d = a; x = 1; y = 0;
        return;
    }
    euclid(b, a%b);
    int t = x;  x = y; y = t - a/b*y;
}
int main()
{
    euclid(500,650);
    cout << x << " " << y << " " << d;
}
