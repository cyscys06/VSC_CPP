#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void UPPER(string & str); // 참조를 통해 str을 대용이름으로 사용

int main()
{
    string text;
    cout << "문자열을 입력하시오 (끝내려면 q): ";
    getline(cin, text);
    while (!(text == "q")) // string이면 큰따옴표 char면 작은따옴표
    {
        UPPER(text);
        cout << text << endl;
        cout << "문자열을 입력하시오 (끝내려면 q): ";
        cin >> text; // 다시입력
    }
    cout << "프로그램 종료.\n";
    return 0;
}

void UPPER(string & str)
{
    for (int i = 0; i < str.length(); i++)
        {
            str[i] = toupper(str[i]); // 한 글자마다 대문자로 바꿔주기(반복문으로 문자 전부 다 바꾸기)
        }
}