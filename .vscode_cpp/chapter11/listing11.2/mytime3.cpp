#include "mytime3.h"

Time::Time() // 입력값 없는 객체면 디폴트로
{
    hours = minutes = 0; 
}

Time::Time(int h, int m) // 입력값 있는 객체면 사용자 정의로
{
    hours = h;
    minutes = m;
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

Time Time::operator+(const Time & t) const
{
    Time sum; // sum이라는 클래스 객체 생성(이 객체는 함수 안에서만 쓰이는 지역변수임)
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum; // 클래스 객체 sum의 복사본을 반환
}

Time Time::operator-(const Time & t) const
{
    Time diff; 
    int tot1, tot2;
    tot1 = t.minutes + (60 * t.hours);
    tot2 = minutes + (60 * hours);
    diff.minutes = (tot2 - tot1) % 60; // 나머지
    diff.hours = (tot2 - tot1) / 60; // 몫
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result; 
    long totalminutes = (hours * mult * 60) + (minutes * mult);
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << "시간, " << t.minutes << "분";
    return os; // 매개변수의 참조값을 반환(즉, 받은 매개변수(객체) 그대로 반환)
}