#include <iostream>
#include <array>
using namespace std;

const int Seasons = 4; // 배열크기
const char* Snames[Seasons] = {"Spring", "Summer", "Fall", "Winter"}; // 사계절을 원소로 가지는 char 포인터형 배열 Sname 선언

void fill(array<double, Seasons> &pa); // pa가 매개변수로 오는 array객체를 참조(데이터 복사 X) -> 직접 입력 받아야 하므로 const 사용 X
void show(const array<double, Seasons> &da); // 출력만 하므로 값을 변경하지 않도록 const로 고정

int main()
{
    array<double, Seasons> expenses; // 크기가 expenses이고 자료형이 double인 array객체 expenses 선언
    fill(expenses); // 매개변수로 array객체 expenses를 사용해 함수 호출
    show(expenses);
    return 0;
}

void fill(array<double, Seasons> &pa) // 계절별 소모 비용 입력
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << "에 소요되는 비용: ";
        cin >> pa[i];
    }
}

void show(const array<double, Seasons> &da) // 계절별 소모 비용 및 사계절 총 소모 비용 출력
{
    double total = 0.0;
    cout << "\n계절별 비용\n";
    for (int i = 0; i < Seasons; i++)
    {
        cout << Snames[i] << ": $" << da[i] << endl;
        total += da[i];
    }
    cout << "총 비용 : $" << total << endl;
}
