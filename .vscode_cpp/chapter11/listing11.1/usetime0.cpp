// 클래스 멤버 사용
#include <iostream>
#include "mytime0.h"

int main()
{
    using namespace std;
    Time planning; // 클래스 객체 생성, 디폴트 생성자 사용(0, 0 저장)
    Time coding(2, 40); // 사용자 정의 생성자 사용해 객체 멤버에 값 할당
    Time fixing(5, 55); // 사용자 정의 생성자 사용해 객체 멤버에 값 할당
    Time total; // 클래스 객체 생성, 디폴트 생성자 사용(0, 0 저장)

    cout << "planning time = ";
    planning.Show(); // planning 객체의 게터를 사용해 멤버값들을 출력
    cout << endl;

    cout << "coding time = ";
    coding.Show(); // coding 객체의 게터를 사용해 멤버값들을 출력
    cout << endl;

    cout << "fixing time = ";
    fixing.Show(); // fixing 객체의 게터를 사용해 멤버값들을 출력
    cout << endl;

    total = coding.Sum(fixing); // coding객체의 멤버값에 fixing객체의 멤버값을 더한 것을 total객체의 멤버값들에 각각 저장 
    cout << "coding.Sum(fixing) = "; // 즉, 두개의 시간을 더한 값을 출력함
    total.Show(); 
    cout << endl;

    return 0;
}