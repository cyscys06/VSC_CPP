#include <iostream>
using namespace std;
int main()
{
    char ch = 'M'; // M에 해당하는 아스키 코드를 char형 변수 ch에 대입
    int i = ch; // 같은 코드를 변수 i에 저장
    cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

    cout << "이 문자 코드에 1을 더해 보겠습니다." << endl;
    ch = ch + 1; // 변수 ch에 저장됐던 코드를 변경(코드에 1 더함)
    i = ch;
    cout << ch << "의 ASCII 코드는 " << i << "입니다." << endl;

    // cout.put() 멤버 함수를 사용해 char형 변수 ch를 출력
    cout << "cout.put(ch)를 사용하여 char형 변수 ch를 화면에 출력: ";
    cout.put(ch);

    // cout.put()을 사용해 문자 상수를 출력
    cout.put('!');

    cout << endl << "종료" << endl;
    
}