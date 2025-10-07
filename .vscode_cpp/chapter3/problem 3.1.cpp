#include <iostream>
using namespace std;
int main()
{
    int cm;
    cout << "키를 센티미터 단위로 입력하시오_" << endl;
    cin >> cm;
    
    const int M = cm / 100;
    const int CM = cm % 100;

    cout << "당신의 키는 " << M << "m " << CM << "cm 입니다." << endl;
}