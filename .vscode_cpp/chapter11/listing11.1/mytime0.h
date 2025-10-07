// 클래스 멤버 선언
#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time // Time이라는 이름의 클래스 생성
{
private: 
        int hours;
        int minutes;
public:
        Time(); // 디폴트 생성자
        Time(int h, int m = 0); // 사용자 정의 생성자
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        Time Sum(const Time & t) const; // 읽기전용으로 취급
        void Show() const;
};
#endif
