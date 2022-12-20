#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 1000;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    cout << rnd.next(1, INF) << '\n';
}