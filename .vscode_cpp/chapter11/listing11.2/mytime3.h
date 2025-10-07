#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
    int hours, minutes;
public:
    Time(); // 디폴트 생성자
    Time(int h, int m = 0); // 사용자 정의 생성자
    void AddMin(int m); // 시간 더하기 함수
    void AddHr(int h); // 시간 빼기 함수
    void Reset(int h = 0, int m = 0); // 객체의 멤버값들을 각각 입력받은값으로 변경하는 함수 
    Time operator+(const Time & t) const; // + 연산자 오버로딩
    Time operator-(const Time & t) const; // - 연산자 오버로딩
    Time operator*(double n) const; // * 연산자 오버로딩
    friend Time operator*(double m, const Time & t) // 인라인함수 선언및정의(friend 키워드 사용, public과 동등한 권한 가지지만 클래스에 속한건 아님)
        { 
            return t * m;
        }
    friend std::ostream & operator<<(std::ostream & os, const Time & t); // << 연산자 오버로딩
};

#endif