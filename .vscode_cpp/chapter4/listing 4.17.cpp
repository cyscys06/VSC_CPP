#include <iostream>
int main()
{
    using namespace std;
    int nights = 1001;
    int * pt = new int; // int형을 지시하는 포인터 pt를 선언(주소 대입 안한상태)  
                        // new 연산자로 새로운 메모리 생성(뒤에 따라오는 자료형이 int이므로 int형의 메모리 생성)
                        // 포인터 변수 pt에 메모리 대입
    *pt = 1001; // 포인터 변수 pt에 대입된 메모리에 값(1001)을 저장


    cout << "nights의 값 = ";
    cout << nights << ": 메모리 위치 " << &nights << endl;
    cout << "int 형";
    cout << "값 = " << *pt << ": 메모리 위치 = " << pt << endl;


    double * pd = new double; // double형을 지시하는 포인터 pd를 선언
    *pd = 10000001.0;         // double형을 저장할 메모리를 대입


    cout << "double 형";
    cout << "값 = " << *pd << ": 메모리 위치 = " << pd << endl;
    cout << "포인터 pd의 메모리 위치: " << &pd << endl;
    cout << "pt의 크기: " << sizeof(pt);
    cout << ": *pt의 크기 = " << sizeof(*pt) << endl;
    cout << "pd의 크기: " << sizeof(pd);
    cout << ": *pd의 크기 = " << sizeof(*pd) << endl;
    return 0;
}
