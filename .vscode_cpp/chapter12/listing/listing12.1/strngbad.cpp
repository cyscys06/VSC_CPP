#include <cstring>
#include "strngbad.h"
using std::cout;

int StringBad::num_strings = 0; // 초기화

StringBad::StringBad(const char * s)
{
    len = std::strlen(s); 
    str = new char[len + 1]; // 문자열 길이 + 1(널문자땜에)만큼의 크기를 new연산자를 통해 설정 후 이를 str에 설정
    std::strcpy(str, s); // 아무것도 없는 포인터 변수 str에 사용자로부터 입력받은 s를 할당함
    num_strings++;
    cout << num_strings << ": \"" << str << "\" 객체 생성\n";
}

StringBad::StringBad() // 객체들이 디폴트로 갖고있는 값들
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "C++"); 
    num_strings++;
    cout << num_strings << ": \"" << str << "\" 디폴트 객체 생성\n";
}

StringBad::~StringBad() // 파괴자를 실행할때 출력되는 것들(하나의 객체(적용된 생성자)마다 각각 파괴자가 하나씩 할당됨)
{
    cout << "\"" << str << "\" 객체 파괴, ";
    --num_strings;
    cout << "남은 객체 수: " << num_strings << "\n";
    delete [] str; // 동적메모리 삭제
} 

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}