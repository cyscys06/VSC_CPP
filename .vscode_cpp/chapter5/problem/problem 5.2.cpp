#include <iostream>
#include <array>
using namespace std;

int main() 
{
    const int ArSize = 100; 
    array<long double, ArSize> factorials; // array 객체를 통해 크기 ArSize이고 자료형 long double인 팩토리얼 선언
    factorials[0] = factorials[1] = 1.0L; // L안붙이면 int형으로 인식
       
    for (int i = 2; i <= ArSize; i++) 
        factorials[i] = i * factorials[i - 1];
    
    cout << "100! = " << factorials[ArSize] << endl;
    return 0;
}
