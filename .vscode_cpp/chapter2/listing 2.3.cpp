#include <iostream>
using namespace std;
int main()
{
    int carrots; // 변수 선언
    // 세미콜론은 끝에 항상, 무조건 붙인다
    cout << "당근을 몇 개나 가지고 있니?\n";
    cin >> carrots; // cin이라는 객체를 통해 사용자로부터 값을 입력받음('>>'기호 사용), 입력받은 값을 변수에 저장
    cout << "여기 2개가 더 있다\n";
    carrots = carrots + 2; // 값을 저장받은 변수의 값을 변경
    cout << "이제 당근은 모두" << carrots << "개이다." << endl; // 변수에 저장된 값을 출력할 때는 따옴표 없이 변수명만 쓴다
    return 0;
}