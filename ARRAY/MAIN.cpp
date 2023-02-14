#include <iostream>
#include "ARRAY.cpp"
using namespace std;

int main()
{
    ARRAY<int> ar;

    ar.push(1);
    ar.push(2);
    ar.push(3);
    ar.push(4);
    ar.push(5);
    ar.push(6);

    ar.push(1);
    ar.push(2);
    ar.push(3);
    ar.push(4);
    ar.push(5);
    ar.push(6);


    ar.print();

    cin.get();
}