#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 100;
int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    int len = 100;
    int lengthStr = rnd.next(1, len);
    string str = rnd.next("[a-z]{" + to_string(lengthStr) + "}");
    len -= lengthStr;
    cout << str;
    while(len)
    {
        int w = rnd.next(1, len);
        string ww = rnd.next("[a-z]{" + to_string(w) + "}");
        cout << ww;  len -= w; if (len >= lengthStr)
        {
            cout << str;
            len -= lengthStr;

        }
    }
    cout << "\n" << str << "\n";
}