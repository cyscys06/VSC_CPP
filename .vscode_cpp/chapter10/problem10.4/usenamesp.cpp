#include <iostream>
#include "namesp.h"
const int SIZE = 3;

int main()
{
    using namespace std;
    
    double data[SIZE] = {12450.5, 20000.0, 32500.75}; // 첫번째 판매 데이터
    SALES::Sales first(data, SIZE);  // 생성자를 통한 객체 초기화 (4분기이므로 3개 입력후 남은자리 0으로 초기화)
    cout << "첫 번째 판매 데이터:\n";
    first.showSales(); // first객체의 인자들을 함수가 쓸 수 있음
    
    SALES::Sales second;  // 인자 없는 객체 -> 대화식 생성자 호출
    
    cout << "두 번째 판매 데이터를 입력하시오:\n";
    second.setSales();  // 사용자 입력으로 데이터 설정
    second.showSales();
    
    return 0;
}