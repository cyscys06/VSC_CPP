#include <iostream>
#include "mytime3.h"
using namespace std;

int main()
{
    Time aida(3, 35);
    Time tosca(2, 48);
    Time temp;

    cout << "Aida와 Tosca:\n";
    cout << aida << "; " << tosca << endl;
    temp = aida + tosca; // + 연산자 오버로딩
    cout << "Aida + Tosca: " << temp << endl;
    temp = aida * 1.17; // * 연산자 오버로딩
    cout << "Aida * 1.17: " << temp << endl;
    cout << "10 * Tosca: " << 10 * tosca << endl;

    return 0;
}