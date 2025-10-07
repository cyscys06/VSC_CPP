#include <iostream>
#include "account.h"
using namespace std;

Account::Account()
{
    name = "Choi Yoo Sung";
    num = "731502-01-354396";
    zan = 27522.0;
}

Account::Account(const std::string a, std::string b, double c) 
{
    name = a;
    num = b;
    zan = c;
}

void Account::output()
{    
    cout << "이름: " << name << endl;
    cout << "계좌번호: " << num << endl;
    cout << "현재 잔액: " << zan << endl;
}

void Account::ipgeum(double money)
{
    zan += money; // 잔액에 입급액 추가
}

void Account::choolgeum(double money)
{
    zan -= money;
}