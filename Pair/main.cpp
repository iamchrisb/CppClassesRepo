#include <iostream>
#include "mypair.h"
#include <string>
#include "pair.h"
#include <stdio.h>
using namespace std;

int main()
{

    int i = 5;
    string s = "Hallo";

    Pair<int,string> p;
    cout << p << endl;
    Pair<int,string> p2 (i,s);
    cout << p2 << endl;
}

