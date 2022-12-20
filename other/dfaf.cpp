#include<bits/stdc++.h>
using namespace std;
const int l2 = 60, l3 = 37, l5 = 25, l7 = 21, l10 = 19;
long long        pw2[l2], pw3[l3], pw5[l5], pw7[l7], pw10[l10];
int       cost[10][10];
void precal()
{
    pw2[0] = pw3[0] = pw5[0] = pw7[0] = pw10[0] = 1; 
    for (int i2  = 1; i2  < l2 ; ++i2 ) pw2 [i2]  =  2 * pw2 [i2  - 1];
    for (int i3  = 1; i3  < l3 ; ++i3 ) pw3 [i3]  =  3 * pw3 [i3  - 1];
    for (int i5  = 1; i5  < l5 ; ++i5 ) pw5 [i5]  =  5 * pw5 [i5  - 1];
    for (int i7  = 1; i7  < l7 ; ++i7 ) pw7 [i7]  =  7 * pw7 [i7  - 1];
    for (int i10 = 1; i10 < l10; ++i10) pw10[i10] = 10 * pw10[i10 - 1];
    cost[1][2] = 0;    cost[1][3] = 0;    cost[1][5] = 0;    cost[1][7] = 0;    
    cost[2][2] = 1;    cost[2][3] = 0;    cost[2][5] = 0;    cost[2][7] = 0;    
    cost[3][2] = 0;    cost[3][3] = 1;    cost[3][5] = 0;    cost[3][7] = 0;   
    cost[4][2] = 2;    cost[4][3] = 0;    cost[4][5] = 0;    cost[4][7] = 0;    
    cost[5][2] = 0;    cost[5][3] = 0;    cost[5][5] = 1;    cost[5][7] = 0;  
    cost[6][2] = 1;    cost[6][3] = 1;    cost[6][5] = 0;    cost[6][7] = 0;  
    cost[7][2] = 0;    cost[7][3] = 0;    cost[7][5] = 0;    cost[7][7] = 1;   
    cost[8][2] = 3;    cost[8][3] = 0;    cost[8][5] = 0;    cost[8][7] = 0;   
    cost[9][2] = 0;    cost[9][3] = 2;    cost[9][5] = 0;    cost[9][7] = 0;   
}

long long VL, VR,L,R,lim;
long long f[l10][l2][l3][l5][l7];
long long magic(long long X, int N, int p2, int p3, int p5, int p7)
{
    if (p2 < 0 || p3 < 0 || p5 < 0 || p7 < 0) return 0; 
    if (N == 0) return (p2 + p3 + p5 + p7 == 0) && (VL <= X && X <= VR); 

    long long mn = X * pw10[N];
    long long mx = mn + pw10[N] - 1;
    if (mx < VL || mn > VR) return 0;

    long long &save = f[N][p2][p3][p5][p7];
    bool memo = (VL <= mn) && (mx <= VR);
    if (memo) if (save != -1) return save;

    long long res = 0;
    if (X == 0) res = magic(0, N - 1, p2, p3, p5, p7); 
    for (int v = 1; v <= 9; ++v)
    {
        int c2 = cost[v][2];
        int c3 = cost[v][3];
        int c5 = cost[v][5];
        int c7 = cost[v][7];
        res += magic(X * 10 + v, N - 1, p2 - c2, p3 - c3, p5 - c5, p7 - c7);
    }
    if (memo) save = res;

    return res;
}
long long solve(int p2 = 0, int p3 = 0, int p5 = 0, int p7 = 0, long long P = 1)
{
    if (P > lim) return 0;

    VL = (L) / P; 
    VR = (R+1) / P;           
    long long res = magic(0, 18, p2, p3, p5, p7); 
    //cout << P << endl;
 
     if (!p3 && !p5 && !p7) res += solve(p2 + 1, p3, p5, p7, P * 2); 
    if (       !p5 && !p7) res += solve(p2, p3 + 1, p5, p7, P * 3); 
     if (              !p7) res += solve(p2, p3, p5 + 1, p7, P * 5); 
                           res += solve(p2, p3, p5, p7 + 1, P * 7); 
    return res;
}
int main()
{
    freopen("lololoin.txt","r",stdin);
    long long x1,x2,ans1,ans2;
    precal();
    cin >> x1 >> x2;
    // L = 1; R = x1;
    // lim = sqrt(R);
    // ans1 = solve();
    L = x1; R = x2;
    lim = sqrt(R);
    ans2 = solve();
    cout << ans2;
}