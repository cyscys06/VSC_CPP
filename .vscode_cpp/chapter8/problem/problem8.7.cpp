#include <iostream>
using namespace std;
const int SIZE1 = 50, SIZE2 = 6, SIZE3 = 3;

struct debts
{
    char name[SIZE1];
    double amount;
};

template <typename T> int SumArray(T arr[], int n);
template <typename T> double SumArray(T * arr[], int n);

int main()
{
    int things[SIZE2] = {13, 31, 103, 301, 310, 130};
    debts mr_E[SIZE3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[SIZE3];

    for (int i = 0; i < SIZE3; i++)
    {
        pd[i] = &mr_E[i].amount;
    }
    cout << "Mr. E의 재산목록 개수:\n";
    cout << SumArray(things, SIZE2) << endl;
    cout << "Mr. E의 채무목록 합계:\n";
    cout << SumArray(pd, SIZE3) << endl;
    return 0;
}

template <typename T> int SumArray(T arr[], int n) // 재산목록 개수
{
    int count;
    for (int i = 0; i < n; i++)
    {
        count++;
    }
return count;
}

template <typename T> double SumArray(T * arr[], int n) // 채무목록 합계
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += *arr[i];
    }
    return total;
}