#include <iostream>
#include <string>
using namespace std;

const int Seasons = 4;
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"};

struct S_exp // S_exp라는 구조체 선언
{
    double expenses[Seasons]; // 크기가 Seasons인 double형 배열 expenses 선언
};

void fill(S_exp * pa); // S-exp 포인터형 변수 pa를 매개변수로 하는 함수 선언(그냥 pa: 데이터 복사, * pa: 원본 참조)
void show(S_exp da);

int main() 
{
    S_exp new_exp;
    fill(&new_exp);
    show(new_exp);
    return 0;
}

void fill(S_exp* pa) // 입력
{
    for (int i = 0; i < Seasons; i++) 
    {
        cout << Snames[i] << "에 소요되는 비용: ";
        cin >> pa->expenses[i];
    }
}

void show(S_exp da) // 출력
{
    double total = 0.0;
    cout << "\n계절별 비용\n";
    for (int i = 0; i < Seasons; i++) 
    {
        cout << Snames[i] << ": " << da.expenses[i] << '\n';
        total += da.expenses[i];
    }
    cout << "총비용: " << total << '\n';
}