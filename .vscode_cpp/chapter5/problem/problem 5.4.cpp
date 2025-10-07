#include <iostream>
#include <cmath>
int main()
{
    using namespace std;

    int a = 100000, b = 100000; 
    int year = 1;    
    int PA , PB; 
    while (PA >= PB) // PA가 PB보다 크거나 같으면 계속 반복, PA가 PB보다 작아지면 반복 종료
    {
        year++; // 블록 마지막에 구문 넣으면 year에 또 1 추가돼서 28 됨
        PA = a + (a / 10 * year);
        PB = b * pow(1.05, year);
    } 

    cout << year << "년 후 A의 투자 가치: " << PA << endl;
    cout << year << "년 후 B의 투자 가치: " << PB << endl;
    cout << "고로 B의 투자 가치는 " << year << "년 만에 A의 투자 가치를 초과했다.";
    return 0;
}