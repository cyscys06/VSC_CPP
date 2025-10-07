#include <iostream>
int main()
{
    using namespace std;
    char ch;

    cout << "타이핑하시면, 반복 수행하겠습니다.\n";
    cin.get(ch);
    while (ch != '.') // ch가 .면 루프 종료되도록 while문의 조건식을 설정
    {
        if (ch == '\n') // ch가 \n이면 if구문 실행
        {
            cout << ch; // ch를 출력
        }
        else // ch가 \n 아니면 else구문 실행
        {
            cout << ch + 1; // ++ch: ch에 1을 더한 값을 출력 
                            // ch + 1: ch를 정수형(아스키코드)으로 저장한 후 그 정수에 1을 더해 출력
        }
        cin.get(ch);
    }
        cout << "\n혼란스럽게 해서 죄송합니다.\n";
        return 0;



}