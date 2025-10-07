#include <iostream>
#include "account.h"
using namespace std;

int main()
{
    Account myAccount; // 클래스 객체 생성(구조체와 같음)
    double deposit; // 입금액
    double withdraw; // 출금액
    int option; // 선택지
    
    cout << "계좌 입출금 프로그램. 다음 선택 사항 중에서 하나를 선택하십시오.\n"
            "1) 정보 출력      2) 입금\n"
            "3) 출금           q) 프로그램 종료\n";
    
    while (cin >> option) 
    {
        switch(option)
            {
	              case 1: myAccount.output(); // 클래스의 멤버함수
                        continue;
	            
                case 2: cout << "입금 액수를 입력하시오: \n";
                          cin >> deposit;
                          while (deposit < 0)
                          {
                            cout << "음수는 입력할 수 없습니다. 다시 입력하십시오.\n";
                          }
                          myAccount.ipgeum(deposit);
                          cout << deposit << "원이 입금되었습니다.\n";
                          continue;
	            
                case 3: cout << "출금 액수를 입력하시오: \n";
                          cin >> withdraw;
                          while (withdraw < 0)
                          {
                            cout << "음수는 입력할 수 없습니다. 다시 입력하십시오.\n";
                          }
                          myAccount.choolgeum(withdraw);
                          cout << withdraw << "원이 출금되었습니다.\n";
                          continue;
                
                default : cout << "다음 선택 사항 중에서 하나를 선택하십시오.\n"
                "a) 정보 출력      b) 입금\n"
                "c) 출금           q) 프로그램 종료\n";
                continue;
            }
    }
    cout << "프로그램을 종료합니다.\n";
    return 0;
}