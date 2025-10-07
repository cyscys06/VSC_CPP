#include <iostream>
using namespace std;

double add(double x, double y); // x + y
double subtract(double x, double y); // x - y
double multiply(double x, double y); // x * y
double divide(double x, double y); // x / y (단, y는 0이 아니다)
double calculate(double a, double b, double (*operation)(double x, double y)); // 임의의 실수 2개를 입력받고, 
                                                                               // 그 2개의 실수에 대해 사칙연산을 진행할 함수 1개도 매개변수로 가지는 계산 함수
int main() 
{
    double (*operations[])(double, double) = {add, subtract, multiply, divide}; // *operations[]: 4개의 함수를 지시하는 포인터형 배열 -> ex) *operations[0]이라면 
                                                                                 // 형식이 (*operations)인 이유: 437p 참조
    const char* operationNames[] = {"덧셈", "뺄셈", "곱셈", "나눗셈"}; // 사용자의 선택지에 따른 인덱스를 가지는 배열 ([0]: 덧셈함수, [1]: 뺄셈함수, [2]: 곱셈함수)
    double num1, num2;
    int choice; // 선택지(선택지는 양의 정수) 
    
    cout << "두 개의 실수를 입력하십시오.(수가 아닌 문자 입력 시 종료)\n";
    cout << "(단, 나눗셈의 경우 첫번째로 입력한 수를 두번째로 입력한 수로 나눔)\n";
    while (true) // 조건이 항상 참 -> while문은 계속 반복만 하므로 조건검사를 블록 내부에서 별도로 실행해야 한다
    {    
        cout << "수를 입력(수가 아닌 문자 입력 시 종료): \n";
        if (!(cin >> num1 >> num2)) // 수가 아닌 문자 입력할떄
        {
            break;
        }
        cout << "수행할 연산을 선택하십시오:\n";
        cout << "1. 덧셈 2. 뺄셈 3. 곱셈 4. 나눗셈\n";
        cout << "선택 (1~4): ";
        
        if (choice < 1 || choice > 4) // 1보다 작거나 4보다 큰 수 입력할때
        {
            cout << "잘못된 입력입니다. 다시 입력하십시오.\n";
            continue;
        }
        else if (num2 == 0 && choice == 4) // 나누는 수가 0이고 사용자가 4번 선택지를 골랐을 때
        {
            cout << "임의의 수를 0으로 나눌 수 없습니다. 다시 입력하십시오.\n";
            continue;
        }
        double result = calculate(num1, num2, operations[choice - 1]); // (사용자가 입력한 수 -1)번 인덱스에 원소로써 들어가있는 사칙연산 함수를 호출
        cout << operationNames[choice - 1] << " 결과: " << result << endl;
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

double add(double x, double y) 
{
    return x + y;
}

double subtract(double x, double y) 
{
    return x - y;
}

double multiply(double x, double y) 
{
    return x * y;
}

double divide(double x, double y) 
{
    return x / y;
}

double calculate(double a, double b, double (*operation)(double x, double y)) // 함수형 매개변수에서 반환형을 double로 하여 함수에서 계산한 값을 다시 리턴받음
{
    return operation(a, b);
}

