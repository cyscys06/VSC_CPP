#include <iostream>
using namespace std;
const int SIZE = 10;

int Fill_array(double arr[], int n); // arr: 배열, size: 배열 크기
void Show_array(const double arr[], int n);
void Reverse_array(double arr[], int n);

int main()
{
    double NUMS[SIZE];

    int num = Fill_array(NUMS, SIZE); // 실제 입력된 개수 저장
    if (num == 0) // 아무것도 입력 안할때
    {
        cout << "입력된 값이 없습니다.\n";
        return 0;
    }

    cout << "입력한 수들을 출력: \n";
    Show_array(NUMS, num);

    cout << "입력한 수들의 순서를 반대로 하여 출력: \n";
    Reverse_array(NUMS, num); // 순서바꾸기
    Show_array(NUMS, num); // 순서가 바뀐 NUMS[] 배열을 출력

    return 0;
}


int Fill_array(double arr[], int n) // 배열에 값 입력
{
    int count = 0;
    cout << "입력할 숫자의 개수 입력: ";
    

    while (!(cin >> count) || count <= 0 || count > n) // 조건 하나라도 만족 하면 루프 실행
    {
        cin.clear(); // 입력버퍼 삭제 
        cout << "잘못된 입력입니다. 숫자를 입력하시오: ";
        cin >> count;
    }

    cout << count << "개의 실수를 입력하시오:\n";
    for (int i = 0; i < count; i++)
    {
        cout << "값 #" << (i + 1) << ": ";
        while (!(cin >> arr[i])) // 실수 입력이 아닐때
        {
            cin.clear();
            cout << "실수가 아닙니다. 다시 입력하시오: ";
        }
    }
    return count;
}


void Show_array(const double arr[], int n) // 배열에 입력된 값 출력 
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void Reverse_array(double arr[], int n) // 배열 순서만 바꿈(출력및 리턴 X) 
{
    for (int i = 0, j = (n - 1); i < j; i++, j--)
    {
        double temp = arr[i]; // 순서 바꾸기
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
