#include "testlib.h"

#include<bits/stdc++.h>

using namespace std;

const int INF = 1000;
string ho[11] = {"Le", "Nguyen", "Tran", "Pham", "Hoang", "Huynh", "Vu", "Vo", "Dang", "Bui", "Ly"};
string ten_dem[11] = {"van", "Dai", "Ngoc", "Dinh", "Dang", "Thi", "Ly", "Bao", "Gia", "Phuc", "Van"};
string ten[11] = {"Huy", "Anh", "Toan", "Tan", "Linh", "Giang", "Bao", "Vu", "Khanh", "Duong", "Truc"};
int main(int argc, char *argv[])
{
	registerGen(argc, argv, 1);
    prepareOpts(argc, argv);
    cout << ho[rnd.next(0, 10)]<< "\n" << ten_dem[rnd.next(0, 10)] << "\n" << ten[rnd.next(0, 10)];
}