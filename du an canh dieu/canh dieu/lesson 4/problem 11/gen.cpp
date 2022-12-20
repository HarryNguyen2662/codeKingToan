#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    int type = opt<int>("type");
    switch (type)
    {
    case 0: //A < 0, B <= 0
        cout << rnd.next(-INF, -1) << ' ' << rnd.next(-INF, 0) << '\n';
        break;
    case 1: //A < 0, B >= 0
        cout << rnd.next(-INF, -1) << ' ' << rnd.next(0,  INF) << '\n';
        break;
    case 2: //A > 0, B <= 0
        cout << rnd.next(1, INF) << ' ' << rnd.next(-INF, 0) << '\n';
        break;
    case 3: //A > 0, B >= 0
        cout << rnd.next(1, INF) << ' ' << rnd.next(0, INF) << '\n';
        break;
    }
}