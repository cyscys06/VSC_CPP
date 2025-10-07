#include <iostream>
#include <cctype> // 문자 관련 함수들의 헤더파일
int main()
{
    using namespace std;
    cout << "분석할 텍스트를 입력하십시오. "
            "입력의 끝을 @으로 표기하십시오.\n";
    char ch;
    int whitespace = 0, digits = 0, chars = 0,
        punct = 0, others = 0;

    cin.get(ch); // 선입력받음
    while (ch != '@') // '@'입력하면 루프 종료
    {
        if (isalpha(ch)) // 알파벳 입력한 경우
            chars++;
        else if (isspace(ch)) // 공백 입력한 경우
            whitespace++;
        else if (isdigit(ch)) // 숫자 입력한 경우
            digits++;
        else if (ispunct(ch)) // 구두점 입력한 경우
            punct++;
        else    
            others++; // 기타 문자 입력한 경우
        cin.get(ch); // 다시 입력받음
    }
    cout << "알파벳: " << chars << endl;
    cout << "공백: " << whitespace << endl;
    cout << "숫자: " << digits << endl;
    cout << "구두점: " << punct << endl;
    cout << "기타: " << others << endl;
    return 0;  
}