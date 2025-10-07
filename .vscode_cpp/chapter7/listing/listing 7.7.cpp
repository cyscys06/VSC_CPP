#include <iostream>
const int MAX = 5; // 배열크기
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n); // const를 사용해 데이터를 고정시킴(보호용)
void revalue(double r, double ar[], int n);

int main()
{
    using namespace std;
    double properties[MAX]; // 부동산(최대 5개, 음수 받으면 바로 종료), 
                            // 함수에서 i를 리턴하므로 size에는 i의 최종 값(루프가 끝난 후의 값)이 할당된다.
    int size = fill_array(properties, MAX); // 부동산 가격을 받아 저장하는 함수
                                            // 함수에서 i를 리턴하므로 size에는 i의 최종 값(루프가 끝난 후의 값)이 할당된다.
    show_array(properties, size); // 입력받은 값들을 다시 보여주는 함수
    if (size > 0)
    {
        cout << "재평가율을 입력하시오: ";
        double factor;
        while (!(cin >> factor)) // 잘못된 입력(숫자 입력 안함) 시 루프 종료
        {
            cin.clear(); // 입력버퍼 삭제
            while (cin.get() != '\n')
                {
                    continue;
                }
            cout << "잘못 입력했습니다. 수치를 입력하세요: ";
        }
        revalue(factor, properties, size); // 각각의 원소(입력받은 부동산 값)에 재평가율을 곱한 값을 출력하는 함수
        show_array(properties, size);
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}


int fill_array(double ar[], int limit) // 반환형 int
{
    using namespace std;
    double temp;
    int i; // 밑에서도 써야해서 for문 밖에서 선언

    for (i = 0; i < limit; i++)
    {
        cout << (i + 1) << "번 부동산의 가격: "; // 최대 5개까지 가격을 입력받는다
        cin >> temp;
        if (!(cin)) // 입력 불량시 true, 지금 cin에는 불일치 데이터 + 개행(enter) 저장돼있음
        {
            cin.clear(); // 입력버퍼 삭제
                {
            while (cin.get() != '\n') 
                    continue; // 다시 입력받음
                }
            cout << "입력 불량. 입력 과정을 끝내겠습니다.\n";
            break;
        }
        else if (temp < 0)
        {
            break;
        }
        ar[i] = temp;
    }
    return i; // 함수에서 i를 리턴
}


// show_array 함수에서 변경은 불가. 다른 함수에서는 바꿀 수 있음(재평가된 값은 실제로 값을 바꾼다)
// 얘는 그냥 값을 출력만 해주는 함수다. 함수 자신이 직접 값을 바꿀 수 없다. 
void show_array(const double ar[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++) // i
    {
        cout << (i + 1) << "번 부동산: ";
        cout << ar[i] << endl;
    }
}


// ar[]의 각 원소에 재평가율 r을 곱한다
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        ar[i] *= r; // 복합연산자: ar[i] = ar[i] * r(부동산 가격에 재평가율 r 곱한값을 다시 배열에 저장)
    }
}