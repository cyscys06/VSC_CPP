#include <iostream>
#include <cstring>  // strlen 사용
using namespace std;

template <typename T> T maxn(T arr[], int n); // 첫번째 매개변수: 배열명 두번째 매개변수: 배열크기
template <> const char * maxn(const char * arr[], int n);

int main() 
{
    int integer[6] = {2, 8, 5, 1, 10, 3};
    cout << "int 배열 최댓값: " << maxn(integer, 6) << endl;

    double demical[4] = {2.5, 9.3, 4.4, 7.1};
    cout << "double 배열 최댓값: " << maxn(demical, 4) << endl;

    const char * strings[5] = // char*형 문자열
    {
        "apple",
        "strawberry", // 가장 긴 문자열
        "banana",
        "grape",
        "watermelon"
    };
    cout << "가장 긴 문자열: " << maxn(strings, 5) << endl;
    return 0;
}

template <typename T> T maxn(T arr[], int n) // 템플릿함수(int, double형 가능)
{
    T max = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max) 
        {
            max = arr[i];
        }
    }
    return max;
}

template <> const char * maxn(const char * arr[], int n) // 특수화 함수(char*일때만 해당)
{
    const char * longest = arr[0];
    for (int i = 1; i < n; i++) 
    {
        if (strlen(arr[i]) > strlen(longest)) 
        {
            longest = arr[i];
        }
    }
    return longest;
}