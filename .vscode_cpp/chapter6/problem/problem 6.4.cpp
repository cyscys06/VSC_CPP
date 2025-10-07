#include <iostream>
using namespace std;
void a(), b(), c(), d(); // 사용자 정의 함수 쓸때는 main함수 밖에서 미리 선언 및 정의 후 main함수 안에서 함수를 호출하여 사용한다.
int main()
{
    const int strsize = 20;
    struct bop
    {
        char fullname[strsize];
        char title[strsize];
        char bopname[strsize];
        int preference; // 0 = fullname, 1 = title, 2 = bopname
    };

    char option;
    cout << "Benevolent Order of Programmers\n"
            "a. 실명으로 일람       b. 직함으로 일람\n"
            "c. BOP아이디로 일람    d. 회원이 지정한 것으로 일람\n"
            "q. 종료\n";
    cout << "원하는 것을 선택하십시오: ";
    while (option != 'q') // q누르면 종료
            {
                cin >> option;
                switch(option)
                {
                case 'a': a();
                          cout << "원하는 것을 선택하십시오: ";
                          continue;
                case 'b': b();
                          cout << "원하는 것을 선택하십시오: ";
                          continue;
                case 'c': c();
                          cout << "원하는 것을 선택하십시오: ";
                          continue;
                case 'd': d();
                          cout << "원하는 것을 선택하십시오: ";
                          continue;
                case 'q': cout << "프로그램을 종료합니다.";
                          break;
                default : cout << "c, p, t, g 중에서 하나를 선택하십시오.  (끝내려면 q)\n";
                          continue;
                }
            }
            return 0;    
}

void a()
{
    cout << "Wimp Macho\n"
            "Raki Rhodes\n"
            "Celia Laiter\n"
            "Hoppy Hipman\n"
            "Pat Hand\n";
}

void d()
{
    cout << "Wimp Macho\n"
            "Junior Programmer\n"
            "MIPS\n"
            "Analyst Trainee\n"
            "LOOPY\n";
}
void b()
{
    cout << "b\n";
}

void c()
{
    cout << "c\n";
}

