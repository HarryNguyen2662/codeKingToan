#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const int INF = 5000;

int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    for (int i = 1; i <= 3; i++)
    {
        inf.readInt(1, INF, "out of range");
        inf.readSpace();
        inf.readInt(1, INF, "out of range");
        inf.readSpace();
        inf.readInt(1, INF, "out of range");
        inf.readEoln();
    }
    inf.readEof();
    return 0;
}
