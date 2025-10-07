#include "Cow.h"

int main() 
{
    Cow cow1("Moo", "먹기", 100);
    Cow cow2("Poo", "자기", 200); 
    Cow cow3 = cow1; // 복사 생성자 사용(초기화)
    Cow cow4;
    cow4 = cow2; // 대입 연산자(대입)

    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();
    cow4.ShowCow();

    return 0;
}
