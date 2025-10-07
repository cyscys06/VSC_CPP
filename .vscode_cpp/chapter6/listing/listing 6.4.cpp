#include <iostream>
int main()
{
    using namespace std;
    cout << "이 프로그램은 하드 디스크를 다시 포맷합니다.\n";
    cout << "하드 디스크에 있는 모든 데이터가 지워집니다.\n";
    cout << "계속하시겠습니까? <y/n> ";
    char ch;
    cin >> ch;
    
    if (ch == 'y' || ch == 'Y') // y 또는 Y를 입력해도 OR연산자로 인해 참으로(사용자가 동의한 것으로) 처리
    {
        cout << "당신에게 분명히 경고를 했습니다.\a\a\n";
    }
    else if (ch == 'n' || ch == 'N')
    {
        cout << "훌륭한 선택입니다. 프로그램을 종료합니다.\n";
    }
    else
    {
        cout << "y나 n을 입력하지 않았습니다. 프로그램을 종료합니다.\n";
    }
    return 0;
}