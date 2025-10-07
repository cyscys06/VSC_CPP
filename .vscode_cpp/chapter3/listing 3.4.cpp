#include <iostream>
#include <climits> // 정수형의 크기에 대한 정보가 들어있는 헤더파일 'climits'를 불러옴

using namespace std;
int main()
{
    int n_int = INT_MAX; // 변수 n_int를 INT_MAX(자료형 int의 최대값) 초기화
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LONG_LONG_MAX; // LONG_LONG_MAX와 LLONG_MAX는 같다

    cout << "int는" << sizeof(int) << " 바이트이다." << endl; // sizeof함수 뒤에 자료형 올때는 괄호 붙여서 넣기
    cout << "short는" << sizeof n_short << " 바이트이다." << endl; //  "   뒤에 변수 올때는 괄호 있어도 없어도 상관 X
    cout << "long은" << sizeof n_long << " 바이트이다." << endl;
    cout << "long long은" << sizeof n_llong << " 바이트이다." << endl;
    cout << endl;

    cout << "최댓값" << endl;
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;
    cout << "int의 최솟값 = " << INT_MIN << endl; // int의 최솟값
    cout << "바이트 당 비트 수 = " << CHAR_BIT << endl; // 1바이트 당 비트 수

}

