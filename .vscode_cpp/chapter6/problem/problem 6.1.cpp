#include <iostream>
#include <cctype> // 문자 관련 함수들의 헤더파일
int main()
{
    using namespace std;
    char ch;
    cout << "알파벳을 입력하십시오." << endl;
    cout << "대문자는 소문자로, " << 
    "소문자는 대문자로 바꿔주는 프로그램입니다." << endl;
    cout << "@을 입력하면 프로그램이 종료됩니다." << endl;

    cin >> ch;
    
    while (ch != '@') // @입력하면 종료
    {
        if (islower(ch)) // 소문자면
            {
                cout << char(toupper(ch));
                cin >> ch;
                continue;
            }
        else if (isupper(ch)) // 대문자면
            {
                cout << char(tolower(ch));
                cin >> ch;
                continue;
            }
    }
    cout << "프로그램이 종료되었습니다." << endl;
    return 0;
} 
