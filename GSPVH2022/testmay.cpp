#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }
 
/* Author: Van Hanh Pham */
 
/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/
 
const int MOD = 998244353;
 
#define MAX   8080
#define LOG   13
int high[MAX + 1], comb[MAX + 1][MAX + 1];
int cwc[MAX + 1][LOG + 1], cac[MAX + 1];
 
void prepare(void) {
    FOR(i, 1, MAX) {
        comb[0][i] = 1;
        comb[i][0] = 1;
    }
    comb[0][0] = 1;
    FOR(i, 1, MAX) {
        comb[i][i] = 1;
        FOR(j, i + 1, MAX) {
            comb[i][j] = comb[i][j - 1] + comb[i - 1][j - 1];
            if (comb[i][j] >= MOD) comb[i][j] -= MOD;
        }
    }
 
    FOR(i, 1, MAX) while (MASK(high[i]) <= i) high[i]++;
 
    cac[1] = 1; cac[2] = 2; cac[3] = 2;
    FOR(i, 4, MAX) {
        int h = high[i] - 1;
        int L = MASK(h - 1) - 1, R = MASK(h) - 1;
        FOR(j, max(L, i - 1 - R), min(R, i - 1 - L))
            cac[i] = (cac[i] + 1LL * cac[j] * cac[i - j - 1]%MOD*comb[j][i - 1] % MOD) % MOD;
    }

    cout << cac[9] << endl;
 
    cwc[2][2] = 2; cwc[3][2] = 2;
    FOR(j, 1, LOG) cwc[1][j] = 1;
 
    FOR(j, 3, LOG) FOR(i, 2, min<int>(MASK(j) - 1, MAX)) {
        cwc[i][j] = 2 * cwc[i - 1][j - 1] % MOD;
        FOR(t, 1, i - 2) cwc[i][j] = (cwc[i][j] + 1LL * cwc[t][j - 1] * cwc[i - t - 1][j - 1] % MOD * comb[t][i - 1]) % MOD;
    }
}
 
int main(void) {
  #ifndef ONLINE_JUDGE
    freopen("hellodking.txt","r",stdin);
    freopen("goodbyedking.txt","w",stdout);
    #else
    //hellooooooo
    #endif
    prepare();
    int n;
    while (cin >> n) {
//        printf("n = %d, h = %d, cwc = %d, cac = %d\n", n, high[n], cwc[n][high[n]], cac[n]);
         cout << cac[n] << endl;
         cout << cwc[n][high[n]] << endl;
        cout << (cwc[n][high[n]] - cac[n] + MOD) % MOD << " " << 0 << endl;
    }
    return 0;
}
 
/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/