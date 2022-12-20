#include<bits/stdc++.h>
using namespace std;
int64_t a, b, k;
int64_t ans = 0;
int64_t msqrt(int64_t x){
    int64_t y = sqrt(x);
    while(y*y > x)
        --y;
    while ((y+1)*(y+1)<=x)
        ++y;
    return y;
}
int main()
{
         freopen("lololoin.txt","r",stdin);

    // freopen("density.inp", "r", stdin);
    // freopen("density.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> k;
    for(int64_t y = 1; y*y*y <= b; ++y){
        int64_t yyy = y*y*y;
        if(yyy < a)
            continue;
        ans += max(0LL,msqrt(min(b,yyy+k))-(msqrt(max(a,yyy-k)-1)+1)+1);
    }
    cout << ans;
}