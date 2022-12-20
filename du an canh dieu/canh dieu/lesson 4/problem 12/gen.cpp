#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    cout << rnd.next(1, 500) << '.' << rnd.next(0, 99) << ' '<< rnd.next(1, 250) << '.' << rnd.next(0, 99) << '\n';
}