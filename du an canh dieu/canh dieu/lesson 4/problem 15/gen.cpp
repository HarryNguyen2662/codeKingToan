#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 5000;

int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    for (int i = 1 ; i <= 3; i++)
    {
        int a = rnd.next(1, INF - 1);
        int b = rnd.next(1, INF - a);
        cout << a << ' ' << b << ' ' << rnd.next(abs(a-b) + 1, a+b-1) << '\n';
    }
}