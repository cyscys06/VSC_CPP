#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <string>

class Account 
{    
private:
    std::string name; // 이름
    std::string num; // 계좌번호
    double zan; // 잔액

    public:
    Account(); // 생성자
    Account(const std::string a, std::string b, double c); // 객체 초기화
    void output(); // 정보출력
    void ipgeum(double money); // 계좌에 돈 액수(매개변수) 입금
    void choolgeum(double money); // 계좌에 돈 액수(매개변수) 출금
};
#endif