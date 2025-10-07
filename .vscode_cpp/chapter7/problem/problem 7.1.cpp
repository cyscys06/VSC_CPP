#include <iostream>
#include <cmath>
double calculate(double x, double y); // x, y 받아서 조화평균 계산  
using namespace std; 

int main()
{
    double first, second;
    cout << "두 수를 입력: ";
    while (cin >> first >> second) // first, second 둘다 입력받아야 true
    {
        if (first == 0 || second == 0) // 둘중 하나라도 0이면 루프 종료
        {
            break;
        }
        cout << "입력한 두 수의 조화평균: " << calculate(first, second) << endl; 
    } 
    cout << "프로그램을 종료합니다.";
    return 0;
}

double calculate(double x, double y) // 함수 정의(반환 안해도 됨)
{
    double harmony = 2.0 * x * y / (x + y); // 조화평균 계산식
    return harmony;
}