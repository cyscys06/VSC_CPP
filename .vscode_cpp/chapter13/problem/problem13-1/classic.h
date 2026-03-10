#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"
#include <iostream>

class Classic : public Cd {
    private: 
        char signature[50]; // 대표곡
    public:
        Classic(char* s1, char* s2, char* s3, int n, double x);
        Classic(Cd & d, char* s1);
        Classic();
        ~Classic();
        virtual void Report() const;
        Classic & operator=(const Classic & c);
};

#endif 
// 클래스 메서드 const 의미 
// const 메서드에서 필드 값 변경 불가능
// const 메서드에서 const가 아닌 메서드 호출 불가능
// const인 클래스 객체가 const인 메서드를 호출 가능