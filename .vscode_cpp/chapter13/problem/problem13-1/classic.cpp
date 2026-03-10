#include "classic.h"
#include "cd.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

// Cd 클래스 메서드
Cd::Cd(char* s1, char* s2, int n, double x) { // 차례대로 연주자 이름, 라벨 이름, 수록곡 수, 연주 시간
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d) {
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd() {}
Cd::~Cd() {}

void Cd::Report() const {
    cout << "연주자 이름: " << performers << endl;

    cout << "라벨 이름: " << label << endl;

    cout << "수록곡 수: " << selections << endl;

    cout << "연주 시간: " << playtime << "분\n";
}

Cd & Cd::operator=(const Cd & d) {
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;

    return *this;
}


// Classic 클래스 메서드
Classic::Classic(char* s1, char* s2, char* s3, int n, double x) // 차례대로 대표곡, 연주자 이름, 라벨 이름, 수록곡 수, 연주 시간 
: Cd(s2, s3, n, x) {
    strcpy(signature, s1);
}

Classic::Classic(Cd & d, char* s1) 
: Cd(d) {
    strcpy(signature, s1);
}

Classic::Classic() {}
Classic::~Classic() {}

void Classic::Report() const {
    cout << "대표곡: " << signature << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic & c) {
    strcpy(signature, c.signature);
    Cd::operator=(c); // 부모 클래스의 오버로딩된 대입 연산자를 호출
    // 부모 클래스의 멤버변수들도 같이 복사됨
    
    return *this;
}