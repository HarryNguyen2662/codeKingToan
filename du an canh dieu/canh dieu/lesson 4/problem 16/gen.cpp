#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 10000000;
const int oo = 2000000;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    int a = rnd.next(1, oo), b =rnd.next(1, oo);
    cout << rnd.next(a + b + 5, INF)<< '.' << rnd.next(0, 9) << '\n' << a << '.' << rnd.next(0, 9) << '\n' << b << '.' << rnd.next(0, 9) << '\n';
}