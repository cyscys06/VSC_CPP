#include <iostream>
struct cyscys06 // struct: 구조체 선언, 구조체명: cyscys06
                // 구조체 선언은 main함수 안에, 밖에 둘다 선언 가능
{               
    char name[20]; // 구조체 내부에 여러가지 자료형의 멤버 선언 가능
                   // char형 멤버에 여러 문자 넣으려면 배열로 만들기)
    int age;   
    float height;  // 멤버명에는 영문자, 밑줄(_), 숫자만 기입 가능
}; // 끝에 세미콜론 붙이기

int main()
{   
    using namespace std;
    cyscys06 profile = {"최유성", 22, 170.9}; // 구조체의 변수(변수명 profile) 생성
                                             //각각의 변수에 알맞는 데이터를 할당(main함수 안에 넣기)
                                             // 쉼표 찍기 마지막 빼고(세미콜론 X)
    cout << profile.name << endl; // 변수 사용할때는 (변수명).(멤버명)으로 쓰기
    cout << profile.age << endl;
    cout << profile.height * 2 << endl;
}