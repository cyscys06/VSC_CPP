// 클래스 멤버 정의
#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hours = minutes = 0; // 변수에 디폴트값 할당
}

Time::Time(int h, int m)
{
    hours = h; // 매개변수로 받은 값 할당
    minutes = m; // 매개변수로 받은 값 할당
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60; // 몫은 hours에
    minutes %= 60; // 나머지는 minutes에
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time & t) const // 매개변수로 오는 t: Time 클래스의 객체 속 멤버들을 그대로 사용하겠다는 뜻  
{
    Time sum; // sum이라는 클래스 객체 생성(이 객체는 함수 안에서만 쓰이는 지역변수임)
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; // 클래스 객체 sum의 복사본을 반환
}

void Time::Show() const
{
    std::cout << hours << "시간, " << minutes << "분";
}
