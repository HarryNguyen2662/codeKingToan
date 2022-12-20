#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const long long INF = 99999999999999;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    long long val_1 = rnd.next(1LL, INF);
    long long x = val_1;
    long long wx = 1;
    while(x)
    {
        wx = wx*10;
        x/= 10;
    }
    cout << val_1 << '.' << rnd.next(0ll, INF/wx);
}
