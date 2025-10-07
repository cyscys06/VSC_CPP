#include <iostream>
const int SIZE = 10;
using namespace std;

int input(double arr[], int n); // arr[]: 매개변수로 배열이 올 것임을 알림, n: 배열크기  
void output(double arr[], int n); 
double average_calculate(double arr[], int n); 

int main()
{
    double score[SIZE];
    
    cout << "골프 스코어를 입력하시오(음수 입력시 종료): ";
    int num = input(score, SIZE);
    output(score, num);
    if (num > 0)
    {
        double average_score = average_calculate(score, num);
        cout << "평균 스코어: " << average_score << endl;
    }
    else 
    {
        cout << "입력된 스코어가 없습니다."; // 입력받은값 하나도 없으면
    }
    return 0;
}

int input(double arr[], int size) // 값 입력 함수
{
    int i;
    for (i = 0; i < size; i++)
    {
        cin >> arr[i];
        if (arr[i] < 0) // 음수입력하면
        {
            cout << "프로그램을 종료합니다.\n";
            break;
        }
    }
    return i; // 입력받은 실제 개수를 반환
}

void output(double arr[], int n) // 값 출력 함수
{
    cout << "여태까지 입력된 골프 스코어:\n";
    for (int j = 0; j < n; j++)
    {
        cout << "# " << (j + 1) << ": "<< arr[j] << endl;
        // 입력받은 값들을 차례로 출력
    }
}

double average_calculate(double arr[], int n) // 평균값만 계산하는 함수(출력 X)
{
    double total = 0, average = 0;
    for (int k = 0; k < n; k++)
    {
        total += arr[k];
    }
    average = total / n;
    return average; // 평균값 반환
}