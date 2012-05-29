#include <iostream>
#include "mypair.h"
#include <string>
#include "pair.h"

using namespace std;

int main()
{
   // cout << "Hello World!" << endl;
   // cout << myMax(5, 7.0) << endl;

    int i = 5;
    string s = "Hallo";

    Pair<int,string> p;
    cout << p << endl;
    Pair<int,string> p2 (i,s);

    //cout << p << endl;

   // cout << p.first();
    //cout << p;
}

