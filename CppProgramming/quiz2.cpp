#include <iostream>
using namespace std;

int main() {
    int a, b, c, temp;

    cin >> a >> b >> c; // 100미만 서로다른 정수 입력
    
    temp = a;
    a = c;
    c = b;
    b = temp;

    cout << a << b << c;

    return 0;
}