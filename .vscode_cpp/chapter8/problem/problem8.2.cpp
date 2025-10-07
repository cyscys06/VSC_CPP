#include <iostream>
using namespace std;

struct CandyBar 
{
    const char * brand;  
    double weight;
    int calories;
};

void set(CandyBar & cb, const char * brand = "Millennium Munch", double weight = 2.85, int calories = 350); // 디폴트값 할당
void show(const CandyBar & cb); // cb: 참조                                                                 // 문자열: 읽기전용 데이터이므로 const 사용

int main() 
{
    CandyBar info;
    set(info); // 구조체 멤버에 값 설정
    show(info); // 구조체 멤버 출력
    return 0;
}

void set(CandyBar & cb, const char * brand, double weight, int calories) // 함수 정의에는 디폴트값 안씀
{
    cb.brand = brand;  
    cb.weight = weight;
    cb.calories = calories;
}

void show(const CandyBar & cb) // 출력 
{
    cout << "회사: " << cb.brand << endl;
    cout << "중량: " << cb.weight << endl;
    cout << "칼로리: " << cb.calories << endl;
}


