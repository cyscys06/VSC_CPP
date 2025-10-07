#include <iostream>
using namespace std;

long long factorial(int n); // 팩토리얼 계산 함수

int main() 
{
    int num;
    cout << "팩토리얼을 계산할 숫자를 입력하시오(숫자가 아닌 수 입력 시 종료): ";

    while (cin >> num) // num 자료형이 int이므로 int형 값 입력 못받으면 false, 루프 종료
    {
        cout << num << "! = " << factorial(num) << endl;
        cout << "팩토리얼을 계산할 숫자를 입력하시오(숫자가 아닌 수 입력 시 종료): ";
    }
    cout << "프로그램 종료.";
    return 0;
}

long long factorial(int n)
{
    if (n == 0 || n == 1) // n이 0 또는 1일때(0! = 1! = 1)
        return 1;
    return n * factorial(n - 1);  // factorial(5) = 5 * factorial(4)
}                                 // factorial(4) = 4 * factorial(3)
                                  // ... factorial(2) = factorial(1)(factorial(1) = 1)
                                  // => 5 * 4 * 3 * 2 * 1 = 5!를 반환
