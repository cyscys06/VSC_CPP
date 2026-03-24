#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Pro_Manage();
void Input_Num();
bool isTypeDouble(double n1);
void calculateInt(int a, double b);
void calculateDouble(double b, double d);
void Add(int a, double b);
void Add(double b, double d);
void Sub(int a, double b);
void Sub(double b, double d);
void Mul(int a, double b);
void Mul(double b, double d);
void Div(int a, double b);
void Div(double b, double d);

int main() {
    Pro_Manage();

    return 0;
}

void Pro_Manage() {
    Input_Num();
}

void Input_Num() {
    double n1, n2;
    char symbol;
    
    cout << "숫자 입력: 정수, 실수만 입력 가능\n";
    cout << "기호 입력: +, -, *, /, = 입력시 종료\n";
    
    do {
        
        cin >> n1;
        cin >> symbol;

        if (isTypeDouble(n1)) {

        } else {

        }
    } while (symbol == '=');
    
}

bool isTypeDouble(double n1) {
    double rst;
    int nm;

    nm = int(n1); // n1이 실수인지 정수인지 판별
    rst = n1 - nm; // 소수부 구해서 rst에 저장

    return rst > 0;
}

void calculateInt(int a, double b) {

}

void calculateDouble(double b, double d) {

}

void Add(int a, double b) {
    int nm1;

    nm1 = a + b;
    cout << "Two num Add: ";
    cout << nm1 << endl;
}

void Add(double b, double d) {
    double nm1;
    
    nm1 = b + d;
    cout << "Two num Add: ";
    cout << nm1 << endl;
}

void Sub(int a, double b) {
    int nm1;

    nm1 = a - b;
    cout << "Two num Add: ";
    cout << nm1 << endl;
}

void Sub(double b, double d) {
    double nm1;
    
    nm1 = b - d;
    cout << "Two num Add: ";
    cout << nm1 << endl;
}

void Mul(int a, double b) {
    int nm1;

    nm1 = a * (int)b;
    cout << "Two num Mul: ";
    cout << nm1 << endl;
}

void Mul(double b, double d) {
    double nm1;

    nm1 = b * d;
    cout << "Two num Mul: ";
    cout << nm1 << endl;
}

void Div(int a, double b) {
    int nm1;

    nm1 = a / b;
    cout << "Two num Mul: ";
    cout << nm1 << endl;
}

void Div(double b, double d) {
    double nm1;

    nm1 = b / d;
    cout << "Two num Div: ";
    cout << nm1 << endl;
}

