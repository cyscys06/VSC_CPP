#include <iostream>
using namespace std;
const int MAX = 5; // 배열 크기

double* fill_array(double * begin, double * end);  // 입력 함수
void show_array(const double * begin, const double * end);  // 출력 함수
void revalue(double r, double * begin, double * end);  // 재평가 함수
// 포인터 시작 begin, 종료 포인터 end
int main()
{
    double properties[MAX];
    double * last = fill_array(properties, properties + MAX); // 시작점 + 배열 크기(MAX)
                                                             // = 배열 마지막 원소의 주소 바로 다음 값
    show_array(properties, last);
    if (last > properties) 
    {
        cout << "재평가율을 입력하시오: ";
        double factor;
        while (!(cin >> factor)) // 잘못된 입력 처리
        {
            cin.clear(); // 입력버펴 삭제
            while (cin.get() != '\n')
                continue;
            cout << "잘못 입력했습니다. 다시 가격을 입력하시오: ";
        }
        revalue(factor, properties, last); 
        show_array(properties, last);
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}

double* fill_array(double * begin, double * end) // 배열 입력
{
    double temp;
    double * ptr; // 시작점인 포인터 변수 ptr
    
    for (ptr = begin; ptr < end; ptr++)
    {
        cout << (ptr - begin + 1) << "번 부동산의 가격: ";
        if (!(cin >> temp)) // 입력 오류 발생할때
        {
            cin.clear();
            while (cin.get() != '\n')
                {
                    continue;
                }
            cout << "입력 불량. 입력 과정을 종료합니다.\n";
            break;
        }
        else if (temp < 0) // 음수 입력할때
        {
            break;
        }
        *ptr = temp; // 배열에 값 저장
    }
    return ptr; // 마지막으로 채워진 위치 반환
}

void show_array(const double * begin, const double * end) // 배열 출력
{
    for (const double * ptr = begin; ptr < end; ptr++)
    {
        cout << (ptr - begin + 1) << "번 부동산: " << *ptr << endl;
    }
}

void revalue(double r, double* begin, double* end) // 배열 값 재평가
{
    for (double * ptr = begin; ptr < end; ptr++)
    {
        *ptr *= r; // 모든 원소에 재평가율 곱하기
    }
}
