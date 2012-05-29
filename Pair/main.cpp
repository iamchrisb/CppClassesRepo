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

    int i1 = 2;

    Pair<int,string> p;
    cout << p << endl;
    Pair<int,string> p2 (i,s);
    p = p2;
    cout << "after p = p2 " << p << endl;
    Pair<int,int> p1(i1,i);
    //geht nicht schon der Compiler meckert
//    p = p1;
//    cout << "after p = p1 " << p << endl;
    Pair<int,string> p3(p2);
    cout << "after p3(p2) " << p3 << endl;
    //cout << p << endl;

   // cout << p.first();
    //cout << p;
}

