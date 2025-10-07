#include <iostream>
using namespace std;
const int SIZE1 = 50, SIZE2 = 6, SIZE3 = 3;

struct debts
{
    char name[SIZE1];
    double amount;
};

template <typename T> void ShowArray(T arr[], int n);
template <typename T> void ShowArray(T * arr[], int n);

int main()
{
    int things[SIZE2] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[SIZE3] =
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
    cout << "Mr. E의 재산목록:\n";
    ShowArray(things, SIZE2);
    cout << "Mr. E의 채무목록:\n";
    ShowArray(pd, SIZE3);
    return 0;
}

template <typename T> void ShowArray(T arr[], int n)
{
    cout << "템플릿 A\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template <typename T> void ShowArray(T * arr[], int n)
{
    cout << "템플릿 B\n";
    for (int i = 0; i < n; i++)
    {
        cout << *arr[i] << ' ';
    }
    cout << endl;
}