#include <iostream>
int main()
{
    using namespace std;
    char EngF[20];
    char EngL[20];
    char WHJ; // WHJ: 원하는 학점
    int age;
    cout << "영문 퍼스트 네임(이름):_\b";
    cin.getline(EngF, 20);
    cout << "영문 라스트 네임(성):_\b";
    cin >> EngL;
    cout << "학생이 원하는 학점:_\b";
    cin >> WHJ;
    cout << "나이:_\b";
    cin >> age;
    
    int num1 = WHJ;
    int num2 = num1 + 1;
    char HJ = num2;

    cout << "성명: " << EngL << ", " << EngF << endl;
    cout << "학점: " << HJ << endl;
    cout << "나이: " << age << endl;
    return 0;
}