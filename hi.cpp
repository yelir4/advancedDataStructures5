#include <stdio.h>
#include <iostream>
using namespace std;

// random side tester
// 2/8/23

int main(void) {
    char lol[] = "abc";

    cout << lol << endl;
    cout << lol[1] << endl;
    cout << sizeof(lol) << endl << endl;

/*
    char lmao[];
    lmao = new char[4];
    lmao[2] = 'b';

    cout << lmao << endl;
    cout << lmao[1] << endl;
    cout << sizeof(lmao) << endl << endl;
    */

    char * XD = new char[4];
    XD[0] = 'c';
    XD[1] = 'A';
    XD[2] = 'l';

    cout << XD << endl;
    cout << *(XD+1) << endl;
    cout << sizeof(*XD) << endl << endl;
}