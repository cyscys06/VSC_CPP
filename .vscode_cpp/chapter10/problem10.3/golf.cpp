#include <iostream>
#include "golf.h"
#include <cstring>
using namespace std;

golf::golf() // 선수 이름과 핸디캡 초기화
{
    fullname[0] = '\0';
    handicap = 0;
}

golf::golf(const char* name, int hc) // 생성된 객체의 인자들을 멤버 데이터에 전달
{
    strncpy(fullname, name, (len - 1));
    fullname[len - 1] = '\0'; // 읽기전용 데이터이므로 마지막 반드시 널문자로 종료
    handicap = hc;
}

int golf::setgolf() // 사용자로부터 입력 요청
{
    char temp[len];

    cout << "골프 선수 이름을 입력하세요: ";
    cin.getline(temp, len);
    
    if (temp[0] == '\0') // 입력된게 없으면
        return 0;
    
    strncpy(fullname, temp, len - 1);
    fullname[len - 1] = '\0';  

    cout << "핸디캡을 입력하세요: ";
    cin >> handicap;
    cin.get(); // 개행 문자 처리

    return 1;
}

void golf::sethandicap(int hc) // 핸디캡 멤버 데이터만 따로 변경하는 함수
{
    handicap = hc;
}

void golf::showgolf() const // 정보 출력
{
    cout << "이름: " << fullname << endl;
    cout << "핸디캡: " << handicap << endl;
}