#include <iostream>
#include <cstring>  
using namespace std;

struct stringy // 구조체 선언
{
    char * str;  // 문자열
    int ct;     // 문자열 길이
};

void set(stringy & by, const char * tg);
void show(const stringy & by, int n = 1);
void show(const char * cstr, int n = 1);

int main() 
{
    stringy beany;
    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);
    show(beany);         // 한번 출력
    show(beany, 2);      // 두번 출력(n = 2로 다시 초기화해줌)

    testing[0] = 'D'; // 문자열 인덱스값 변경
    testing[1] = 'u';

    show(testing);       // 변경된 testing 출력
    show(testing, 3);    // 세번 출력
    show("Done!");       // "Done!"이라는 문자열을 매개변수로 하여 출력("Done!"도 문자열이므로)
    return 0;
}

void set(stringy & by, const char * tg) // 첫번째 매개변수: 구조체형 변수 두번째 매개변수: 문자열
{                                       // 참조 사용: 대용이름 by, tg
    by.ct = strlen(tg); // 구조체의 ct멤버에 문자열 길이 복사          
    by.str = new char[by.ct + 1]; // ct: 정수(문자열 길이) -> 문자열로 변환하려면 문자열 길이에 +1(널문자가 들어갈 자리)해줌
                                  // strlen함수가 문자열 길이를 읽을때 널문자는 읽지 않음
                                  // 근데 문자열로 변환하려면 널문자가 들어갈 자리가 있어야 하므로 추가해준것
    strcpy(by.str, tg); // 구조체의 str멤버에 문자열 tg 복사        
}

void show(const stringy & by, int n = 1) // stringy형 데이터 전용함수(숫자 매개변수 없어도 n 디폴트값 1 있음)
{
    for (int i = 0; i < n; ++i) // n번 반복
    {
        cout << by.str << endl;
    }
}

void show(const char * cstr, int n = 1) // char*형 전용함수(함수 오버로딩)
{
    for (int i = 0; i < n; ++i) 
    {
        cout << cstr << endl;
    }
}