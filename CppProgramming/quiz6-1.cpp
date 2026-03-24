#include <iostream>
using namespace std;

bool checkType(double n1);
void Input_Num();
template<typename T>
T calculate(T sum, T num, char symbol);

int main() {
    Input_Num();
    return 0;
}

bool checkType(double n1) {
    return (n1 - (int)n1) == 0;  // true면 정수
}

template<typename T>
T calculate(T sum, T num, char symbol) {
    switch (symbol) {
        case '+': return sum + num;
        case '-': return sum - num;
        case '*': return sum * num;
        case '/': return sum / num;
        default:
            cout << "잘못된 입력입니다.\n";
            return sum;
    }
}

void Input_Num() {
    cout << "계산식 입력 프로그램\n";
    cout << "숫자 입력: 정수, 실수만 입력 가능\n";
    cout << "기호 입력: '+', '-', '*', '/'('=' 입력시 종료)\n";

    double num;
    char symbol;
    cin >> num >> symbol;

    if (checkType(num)) {
        int sum = num;
        while (symbol != '=') {
            double tmp; cin >> tmp;
            sum = calculate(sum, (int)tmp, symbol);
            cin >> symbol;
        }
        cout << "최종값: " << sum;
    } else {
        double sum = num;
        while (symbol != '=') {
            double tmp; cin >> tmp;
            sum = calculate(sum, tmp, symbol);
            cin >> symbol;
        }
        cout << "최종값: " << sum;
    }
}