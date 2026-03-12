#include <iostream>
using namespace std;

int main() {
    int a, b, c, m1, m2, m3;

    cin >> a >> b >> c;

    m1 = (a > b && a > c) ? a : ((b > c) ? b : c);
    m2 = ((a > b && a < c) || (a < b && a > c)) ? a : ((b > c) ? c : b);
    m3 = (a < b && a < c) ? a : ((b < c) ? b : c);
    
    cout << m1 << m2 << m3;

    return 0;
}