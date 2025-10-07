#include <iostream>
#include "strngbad.h"
using namespace std;

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
    {
        cout << "내부 블록 시작.\n";
        StringBad headline1("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spanish Leaves Bowl for Dollars");
        cout << "headline1: " << headline1 << endl;
        cout << "headline2: " << headline2 << endl;
        cout << "sports: " << sports << endl;
        callme1(headline1);
        cout << "headline1: " << headline1 << endl;
        callme2(headline2);
        cout << "headline2: " << headline2 << endl;
        cout << "하나의 객체를 다른 객체로 초기화:\n";
        StringBad knot;
        knot = headline1;
        cout << "knot: " << knot << endl;
        cout << "이 블록을 빠져나옴.\n";
    }
    cout << "main함수 끝\n";
    return 0;
}

void callme1(StringBad & rsb)
{
    cout << "참조로 전달된 StringBad:\n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb)
{
    cout << "값으로 전달된 StringBad:\n";
    cout << "   \"" << sb << "\"\n";
}