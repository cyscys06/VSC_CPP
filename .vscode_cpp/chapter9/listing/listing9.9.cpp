#include <iostream>
using namespace std;
const int SIZE = 10; // 문자 최대 9개까지
void strcount(const char * str); // 읽기 전용 데이터(const char * str)

int main()
{
    char input[SIZE], next;

    cout << "english sentence:\n";
    cin.get(input, SIZE); // 입력받은 값을 배열크기 SIZE의 배열 input에 할당
    while (cin)
    {
        cin.get(next);
        while (next != '\n')
        {
            cin.get(next);
        }
        strcount(input);
        cout << "next sentence(empty str to quit):\n";
        cin.get(input, SIZE);
    }
    cout << "quit program.\n";
    return 0;
}

void strcount(const char * str)
{
    static int total = 0; // 정적 지역 변수(링크 X)
    int count = 0; // 자동 지역 변수(자동변수)

    cout << "\"" << str << "\"is ";
    while (*str++)
    {
        count++; // 문자열의 문자 개수 카운팅 루프
    } 
    total += count; // 문자 개수 총합에 문자 개수 더하기
    cout << count << " alphabets.\n"; 
    cout << "totally " << total << " alphabets.\n";
}