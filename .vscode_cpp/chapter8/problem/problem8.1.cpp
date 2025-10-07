#include <iostream>
#include <string>
using namespace std;
void print(string &a);
void print(string &a, int b); // b: 문자열 뒤에 입력하는 0아닌 숫자

int main()
{
    string word = "안녕하세요."; // 문자열 저장 변수
    int count = 0, num; // num: 사용자의 숫자입력
    cout << "숫자 0을 입력하면 문자열을 한번 출력,\n";
    cout << "0이 아닌 수를 입력하면 함수 호출 횟수만큼 문자열 출력.\n";
    cout << "숫자 입력: ";
    cin >> num;
    while (num == 0)
    {
        print(word);
        count++; // count: 문자열 출력 횟수 저장
        cin >> num;
    }
    print(word, count);
    return 0;
}

void print(string &a)
{
    cout << a << endl;
}

void print(string &a, int b)
{
    cout << "여태까지 함수가 호출된 횟수: " << b << endl;
    cout << "함수를 " << b << "번 출력:\n";
    for (int i = 0; i < b; i++)
    {
        cout << a << endl;
    }
}