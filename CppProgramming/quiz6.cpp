#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Pro_Manage();
bool checkType(double n1);
int calculate(int sum);
double calculate(double sum);

// 정수 연산
int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
int Div(int a, int b);

// 실수 연산
double Add(double b, double d);
double Sub(double b, double d);
double Mul(double b, double d);
double Div(double b, double d);

double num;
char symbol = '\0';

int main() {
    Pro_Manage();

    return 0;
}

void Pro_Manage() {
    cout << "계산식 입력 프로그램\n";
    cout << "숫자 입력: 정수, 실수만 입력 가능\n";
    cout << "기호 입력: '+', '-', '*', '/'('=' 입력시 종료)\n";
    
    cin >> num;
    cin >> symbol;

    if (checkType(num)) {
        double sum = num;
        while (symbol != '=') {
            cin >> num;
            sum = calculate(sum);
            cin >> symbol;
        }
        cout << "최종값: " << sum;
    } else {
        int sum = num;
        while (symbol != '=') {
            cin >> num;
            sum = calculate(sum);
            cin >> symbol;
        }
        cout << "최종값: " << sum;
    }
}

bool checkType(double n1) {
    double rst;
    int nm;

    nm = int(n1); // n1이 실수인지 정수인지 판별
    rst = n1 - nm; // 소수부 구해서 rst에 저장

    return rst > 0; // true면 실수, false면 정수
}

int calculate(int sum) {
        switch (symbol) {
            case '+':
                sum = Add(sum, (int)num);
                break;
            case '-':
                sum = Sub(sum, (int)num);
                break;
            case '*':
                sum = Mul(sum, (int)num);
                break;
            case '/':
                sum = Div(sum, (int)num);
                break;
            default:
                cout << "잘못된 입력입니다. 다시 입력해 주세요: ";
                break;
        }
    return sum;
}

double calculate(double sum) {
        switch (symbol) {
            case '+':
                sum = Add(sum, num);
                break;
            case '-':
                sum = Sub(sum, num);
                break;
            case '*':
                sum = Mul(sum, num);
                break;
            case '/':
                sum = Div(sum, num);
                break;
            default:
                cout << "잘못된 입력입니다. 다시 입력해 주세요: ";
                break;
        }
    return sum;
}

// 정수 연산
int Add(int a, int b) { return a + b; }
int Sub(int a, int b) { return a - b; }
int Mul(int a, int b) { return a * b; }
int Div(int a, int b) { return a / b; }

// 실수 연산
double Add(double b, double d) { return b + d; }
double Sub(double b, double d) { return b - d; }
double Mul(double b, double d) { return b * d; }
double Div(double b, double d) { return b / d; }


