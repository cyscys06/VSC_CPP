#include <iostream>
using namespace std;
const int SIZE = 5;

template <typename T> T max5(T arr[SIZE]);
int main() 
{
    int intArr[SIZE] = {2, 10, 4, 9, 5};
    double doubleArr[SIZE] = {2.2, 10.4, 6.4, 1.5, 9.6};

    cout << "int 배열의 최댓값: " << max5(intArr) << endl;
    cout << "double 배열의 최댓값: " << max5(doubleArr) << endl;
    return 0;
}

template <typename T> T max5(T arr[SIZE]) // '반환형 T고 크기 5인 배열 arr'을 매개변수로 가지고 반환형이 T인 함수 max5 선언
{
    T max = arr[0]; // 최대값 max를 일단 arr[0]으로 초기화 해놓고
    for (int i = 1; i < 5; i++) 
    {
        if (arr[i] > max) // max보다 큰값 나오면
        {
            max = arr[i]; // 그값을 max로 변경 -> 결론적으로 max에는 배열의 최대값이 할당
        }
    }
    return max; // 최대값 반환
}
