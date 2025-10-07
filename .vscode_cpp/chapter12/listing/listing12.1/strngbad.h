#include <iostream>
#ifndef STRNGBAD_H_
#define STRNGBAD_H_

class StringBad
{
private:
    char * str; // 문자열
    int len; // 길이
    static int num_strings; // 객체 수
public:
    StringBad(const char * s); // 사용자 정의 생성자
    StringBad(); // 디폴트 생성자
    ~StringBad(); // 파괴자(new 연산자 사용할거기 때문에 delete로 new 삭제하는 파괴자 하나 필요)
    friend std::ostream & operator<<(std::ostream & os, const StringBad & st); // <<연산자 오버로딩
                                                                               // friend 함수이므로 ostream객체(cout)과 StringBad의 객체 둘다 필요
};
#endif