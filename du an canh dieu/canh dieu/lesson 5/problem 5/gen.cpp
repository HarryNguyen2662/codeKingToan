#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 10000;
int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    int len = rnd.next(1, INF);
    string str = rnd.next("[a-z]{" + to_string(len) + "}");
    int q = rnd.next(1, 100);
    cout << str << "\n";
    cout << q << "\n";
    while(q--)
    {
        int r = rnd.next(1, len);
        int l = rnd.next(1, r);
        cout << l-1 << " "  << r - 1 << "\n";
    }
}