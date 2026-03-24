#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;

void Pro_Manage();
void Input_Num();
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
    double rst;
    int nm;

    cout << "Input Two Number" << endl;
    cin >> n1 >> n2;

    nm = int(n1); // n1이 실수인지 정수인지 판별
    rst = n1 - nm; // 소수부 구해서 rst에 저장

    if (rst > 0) {
        Add(n1, n2); // 처음값 실수면 실수연산
        Sub(n1, n2);
        Mul(n1, n2);
        Div(n1, n2);
    } else {
        Add(nm, n2); // 처음값 정수면 정수연산(소수부분 버리고 계산)
        Sub(nm, n2);
        Mul(nm, n2);
        Div(nm, n2);
    }
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

