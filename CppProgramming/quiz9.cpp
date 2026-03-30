#include <iostream>
using namespace std;

bool isInt(double n);
int Num(int f1, double f2);
double Num(double f1, double f2);

int main() {
    double f1, f2;
    int nm;

    cin >> f1 >> f2;

    if (isInt(f1)) {
        cout << Num((int)f1, f2);
    } else {
        cout << Num(f1, f2);
    }

    return 0;
}

bool isInt(double n) {
    return (n - (int)n) == 0; // true면 정수
}

int Num(int f1, double f2) {
    return f1 + f2;
}

double Num(double f1, double f2) {
    return f1 - f2;
}